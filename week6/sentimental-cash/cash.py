from cs50 import get_float

def main():
    while True:
        dollars = get_float("Change owed: ")
        cents = round(dollars * 100)

        if cents > 0:
            break

    print(calculate(cents))

def calculate(cents):
    quarters = cents // 25
    dimes = (cents % 25) // 10
    nickels = ((cents % 25) % 10) // 5
    pennies = ((cents % 25) % 10) % 5

    return quarters + dimes + nickels + pennies


if __name__ == "__main__":
    main()