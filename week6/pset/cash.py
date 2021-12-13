from cs50 import get_float


def somme():
    money = get_float("Change owed: ")
    if money < 0:
        somme()
    else:
        calculate(money)  
        

def calculate(money):
    cents = round(money * 100)
    counts = 0
    while cents >= 25:
        counts += 1
        cents -= 25
    while cents >= 10:
        counts += 1
        cents -= 10
    while cents >= 5:
        counts += 1
        cents -= 5
    while cents >= 1:
        counts += 1
        cents -= 1
    print(counts)


somme()
