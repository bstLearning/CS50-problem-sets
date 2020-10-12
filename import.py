# imports data from a CSV spreadsheet.
# usage on prompt: python import.py characters.csv

from sys import argv, exit
from cs50 import SQL 
import csv

def main():
    if len(argv) != 2:
        print("Usage: python import.py characters.csv")
        exit(1)
    
    #print("...accessing...")       
    db = SQL("sqlite:///students.db")

    with open(argv[1], "r") as student:
        reader = csv.DictReader(student)
        for row in reader:
            firstName = row['name'].split()[0]
            lastName = row['name'].split()[-1]
            counter = len(row['name'].split())
            if counter != 2:
                middleName = row['name'].split()[1]
            else:
                middleName = None
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", 
            firstName, middleName, lastName, row['house'], row['birth'])



main()

