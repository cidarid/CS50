from cs50 import get_float
moneyValues = [25, 10, 5, 1]
money = round(100 * get_float("Change owed: "))
while (money < 0):
    money = round(100 * get_float("Change owed: "))
i = 0
coinCount = 0
while (i < len(moneyValues)):
    while (money >= moneyValues[i]):
        coinCount += 1
        money -= moneyValues[i]
    i += 1
print(coinCount)