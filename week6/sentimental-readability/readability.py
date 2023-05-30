from cs50 import get_string

def main():
    input = get_string("Text: ")
    check(input)


def check(input):
    sentences = 0
    words = 1
    grade = 0
    letters = 0

    for i in range(len(input)):
        if input[i] == '.' or input[i] == '?' or input[i] == '!':
            sentences += 1
        if input[i] == ' ':
            words += 1
        if input[i].isalpha():
            letters += 1

    grade = 0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8
    if (grade < 1):
        print("Before Grade 1")
    elif (grade >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {round(grade)}")

if __name__ == "__main__":
    main()