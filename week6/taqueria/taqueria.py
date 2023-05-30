def main():
    menu = {
        "Baja Taco": 4.00,
        "Burrito": 7.50,
        "Bowl": 8.50,
        "Nachos": 11.00,
        "Quesadilla": 8.50,
        "Super Burrito": 8.50,
        "Super Quesadilla": 9.50,
        "Taco": 3.00,
        "Tortilla Salad": 8.00
    }
    menu = {k.casefold(): v for k, v in menu.items()}
    calculate(menu)

def calculate(menu):
    x = 0
    try:
        while True:
            item = input("Item: ").lower()
            if item in menu:
                x = x + menu[item]
                print(f"Total: ${x:.2f}")
    except EOFError:
        print("\n")
        return


main()