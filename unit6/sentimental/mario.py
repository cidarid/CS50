# Imports get_int
from cs50 import get_int

validInput = False
# While the input isn't valid, keep prompting the user
while(validInput == False):
    height = get_int("Height: ")
    if (height > 23 or height < 0):
        validInput = False
    else:
        validInput = True
i = 0
# While there are still things left to print...
while (i < height):
    _i = height - i
    while (_i > 1):
        print(" ", end='')
        _i -= 1
    _i = i+1
    while (_i > 0):
        print("#", end='')
        _i -= 1
    print("  ", end='')
    _i = i + 1
    while (_i > 0):
        print("#", end='')
        _i -= 1
    print("")
    i += 1