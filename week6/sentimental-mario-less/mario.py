from cs50 import get_int
# TODO

while True:
    input = get_int("Height: ")
    if input in range(1, 9):
        break

for i in range(input):
    print(" " * (input - 1 - i), end = "")
    print("#" * (i + 1), end = "")
    print("")