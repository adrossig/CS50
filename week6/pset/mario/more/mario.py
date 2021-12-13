from cs50 import get_int


def numbers():
    height = get_int("Height: ")
    if height > 0 and height < 9:
        block(height)
    else:
        numbers()


def print_space(number):
    for i in range(number):
        print(" ", end="")


def print_block(number):
    for i in range(number):
        print("#", end="")


def block(height):
    for i in range(height):
        print_space((height - i - 1))
        print_block((i + 1))
        print("  ", end="")
        print_block((i + 1))
        print("")


numbers()

