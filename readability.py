
# index = 0.0588 * L - 0.296 * S - 15.8

def main():
    string = input("Text: ")
    letters = letters_counter(string)
    words = len(string.split())
    sentences = sentences_counter(string)
    g = grade(letters, words, sentences)
    
    if g > 16:
        print("Grade 16+")
    elif g < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(g)}")
    
    
def letters_counter(str):
    letters = 0
    for l in str:
        if l.isalnum():
            letters += 1
    return letters
    
    
def sentences_counter(str):
    sentences = 0
    for s in str:
        if s == "!" or s == "." or s =="?":
            sentences += 1
    return sentences
    
    
def grade(letters, words, sentences):
    L = letters / words * 100
    S = sentences / words * 100
    G = 0.0588 * L - 0.296 * S - 15.8
    return G
    
    
main()