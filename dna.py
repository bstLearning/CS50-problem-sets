# count STR(Short Tandem Repeats) in sequences
# The number of times any particular STR repeats varies a lot among individuals. I

from sys import argv, exit
import csv  # reader() or DictReader()
import re


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        # exit(1)
    # else:
        # exit(0)
    
    STRs = getSTRs(argv[1])  # Get STRs list from header of CSV databases
    maxls = sequences_check(argv[2], STRs)  # list of max count from different STRs
    result = checker(argv[1], maxls)
    print(result)
    

# Get STRs list from header of CSV databases
def getSTRs(csvFile) -> list:
    try:
        f = open(csvFile, "r")
    except:
        print("csv file not found.")
        return False
    header = []
    for row in csv.reader(f):  # csv.reader(file) return a pointer? to 2D list, 貌似只當迭代器不能直接印出
        header = row
        break
    f.close()
    header.pop(0)  # header.remove(header[0])
    return header
  

# loading sequences file and count STR repeated consecutively in it 
def sequences_check(txtFile, STRs) -> list:
    try:
        f = open(txtFile, "r")
    except:
        print("txt file not found")
        return False
    # count how many times the STR repeats consecutively 
    # return the number of maximum count
    string = f.read()
    maxcount = []
    for i in range(len(STRs)):
        groups = re.findall(fr'(?:{STRs[i]})+', string)  # >>> when i put string place as f.read(), ValueError at max()
        try:
            largest = max(groups, key=len)  # largest as str
        except ValueError: # when groups is empty list
            continue  # or pass ?
        maxcount.append(len(largest) // len(STRs[i]))
    f.close()
    return maxcount


# check: to whom the max STR belongs?
def checker(csvFile, maxls) -> str:
    try:
        f = open(csvFile, "r")
    except:
        print("csv file not found.")
        return False
    
    result = "No match"
    next(csv.reader(f))  # skip first item(header) of iterator
    
    for row in csv.reader(f):  # row is a list of str
        name = row[0]
        row.pop(0)   # >>>>> row = row.pop(0) <<<< row become the elem row[0] 
        row_int = list(map(int, row))  # map() return an iterator, list() casting it
        if row_int == maxls:
            result = name
    f.close()
    return result
    

main()