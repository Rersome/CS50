from pyfiglet import Figlet
from sys import argv
from sys import exit
from random import randrange

figlet = Figlet()
b = figlet.getFonts()
a = randrange(len(figlet.getFonts()))

if len(argv) == 2:
    print("Invalid usage")
    exit(1)
if len(argv) == 1:
    s = input("Word: ")
    figlet.setFont(font=b[a])
    print(figlet.renderText(s))
    print(b[a])
elif len(argv) == 3:
    if argv[1] != "-f" and argv[1] != "--font" or (argv[2] in b) == False:
        print("Invalid usage")
        exit(1)
    else:
        s = input("Word: ")
        figlet.setFont(font=argv[2])
        print(figlet.renderText(s))
