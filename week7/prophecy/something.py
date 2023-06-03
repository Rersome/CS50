from cs50 import SQL
import csv
from sys import argv

def create_house(house, houses, head):
    count = 0
    for a in houses:
        if a["house"] == house:
            count += 1
    if count == 0:
        houses.append({"house": house, "head": head})

def create_student(name, students):
    count = 0
    for a in students:
        if a["student_name"] == name:
            count += 1
    if count == 0:
        students.append({"student_name": name})

def create_assigments(name, house, assigments):
    count = 0
    for a in assigments:
        if a["student_name"] == name:
            count += 1
    if count == 0:
        assigments.append({"student_name": name, "house": house})

def main():
    db = SQL("sqlite:///roster.db")

    students = []
    houses = []
    assigments = []

    with open(argv[1], "r") as file:
    #with open("prophecy/students.csv", "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            name = row["student_name"]
            house = row["house"]
            head = row["head"]

            create_house(house, houses, head)
            create_student(name, students)
            create_assigments(name, house, assigments)

    for student in students:
        db.execute("INSERT INTO students (student_name) VALUES (?)", student["student_name"])
    for house in houses:
        db.execute("INSERT INTO houses (house, head) VALUES (?,?)", house["house"], house["head"])
    for assign in assigments:
        db.execute("INSERT INTO house_assigments")
        #print(houses)
        #print(assigments)

    #db = SQL("sqlite:///roster.db")
    #db.execute("INSERT INTO students (id, student_name)")

if __name__ == "__main__":
    main()