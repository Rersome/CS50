from cs50 import get_string

def main():
    credit_card = get_string("Number: ")
    number = int(credit_card)

    if (len(credit_card) != 13 and len(credit_card) != 15 and len(credit_card) != 16):
        print("INVALID")
        exit(0)

    if (not check(credit_card)):
        print("INVALID")
        exit(0)

    calculate(number)

def calculate(number):
    while(number > 100):
        number = number // 10

    if (number // 10 == 5) and (0 < number % 10 and number % 10 < 6):
        print("MASTERCARD")
    elif (number // 10 == 3) and (number % 10 == 4 or number % 10 == 7):
        print("AMEX")
    elif (number // 10 == 4):
        print("VISA")
    else:
        print("INVALID")

def check(credit_card):
    nDigits = len(credit_card)
    nSum = 0
    xSum = 0
    isSecond = True

    for i in range(nDigits - 1, -1, -1):
        d = int(credit_card[i])
        isSecond = not isSecond

        if (isSecond == True):
            d = d * 2
            nSum += d // 10
            nSum += d % 10
        elif (isSecond == False):
            xSum += d

    if ((nSum + xSum) % 10 == 0):
        return True
    else:
        return False

if __name__ == "__main__":
    main()