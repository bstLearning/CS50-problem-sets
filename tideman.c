#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        
        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i; /// ranks[rank] refer to an int index of candidates
            return true;
        }
    }
    // TODO
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int n = 0; n < candidate_count; n++)
    {
        for (int j = 1; j < candidate_count - n; j++)
        {
            preferences[ranks[n]][ranks[n+j]]++; /// ranks[n] refer to an int index of candidates
        }
    }
    // TODO
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;  /// candidates[i] is winner in this "pair_count"(idx) pair 
                pairs[pair_count].loser = j;   /// candidates[j] is loser in this "pair_count"(idx) pair
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // Slection sort, decreasing order of strength of victory,
    for (int i = 0; i < pair_count - 1; i++)
    {
        int max_idx = i;
        pair tmp[MAX * (MAX - 1) / 2];
        
        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[max_idx].winner][pairs[max_idx].loser])     ///??? How do I get the number of voters who prefer the prefered candidate?///
            {
                max_idx = j; 
            }
        }
        tmp[i] = pairs[max_idx];
        pairs[max_idx] = pairs[i];
        pairs[i] = tmp[i];
    }
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO   
    int CycleChecker1 = 0;
    int CycleChecker2 = 0;
    for (int i = 0; i < pair_count; i++)
    {
        CycleChecker1 += pairs[i].winner;
        CycleChecker2 += pairs[i].loser;
    }
    if (CycleChecker1 != CycleChecker2)
    {
        for (int i = 0; i < pair_count; i++)
        locked[pairs[i].winner][pairs[i].loser]= 1; /// 1, mean true, mean arrow in graph
    }
    else
    {
        for (int i = 0; i < pair_count - 1; i++) /// -1 prevent creating a cycle
        locked[pairs[i].winner][pairs[i].loser] = 1;
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    bool WinnerChecker[pair_count];
    for (int i = 0; i < pair_count; i++) /// pair_count is as big as locked[][]'s length/width
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[i][j] != 0) /// if !=0, means true in locked[i][j], means an arrow point from i to j
            {
                WinnerChecker[j] = 1; /// if 1 in checker, means the j'th candidate is pointed 
            }
            
        }
    }
    
    for (int i = 0; i < pair_count; i++ )
    {
        if (WinnerChecker[i] == 0) /// if i'th candidate is not pointed by any 
            {
                printf("%s\n", candidates[i]);
            }
    }
    return;
}

