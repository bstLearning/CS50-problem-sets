#  prints a list of students for a given house in alphabetical order.

from sys import argv, exit
from cs50 import SQL 
import csv


def main():
    if len(argv) != 2:
        print("Usage: python roster.py houseNAME")
        exit(1)
    
    #print("...accessing...")       
    db = SQL("sqlite:///students.db")
    
    roster = db.execute('''
    SELECT first, middle, last, birth 
    FROM students 
    WHERE house = ?
    ORDER BY last, first''', argv[1])
    
    for row in roster:
        if row["middle"] != None:
            print(row['first'], row['middle'], row['last'], ", born", row['birth'])
        else:
            print(row['first'], row['last'], ", born", row['birth'])
        
    
    
main()
    