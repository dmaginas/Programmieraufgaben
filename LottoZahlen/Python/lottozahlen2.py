from random import randint

lotto = [] * 6
i = 0

while i < 6:
    zufallszahl = randint(1, 49)
    if lotto.count(zufallszahl) != 0:
        continue
    else:
        lotto.append(zufallszahl)
        i += 1


print(sorted(lotto))
