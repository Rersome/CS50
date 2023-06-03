from cs50 import SQL
import csv
from sys import argv

def main():
    students = []
    db = SQL("sqlite:///roster.db")

    with open(argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            students.append(row)

    for student in students:
        db.execute("INSERT OR IGNORE INTO students (id, student_name) VALUES(?,?)",
                   student["id"],
                   student["student_name"],
                   )
        db.execute("INSERT OR IGNORE INTO houses (house, head) VALUES(?,?)",
                   student["house"],
                   student["head"],
                   )
        db.execute("INSERT OR IGNORE INTO house_assigments (student_id, house_id) VALUES(?,?)",
                   student["id"],
                   student["house"],
                   )


if __name__ == "__main__":
    main()