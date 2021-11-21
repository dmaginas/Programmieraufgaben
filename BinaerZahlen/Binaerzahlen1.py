try:
    eingabe_bin = str(input("Bitte Binärzahl eingeben:"))
    if len(eingabe_bin) % 8 != 0:
          print("Es muss eine Binärzahl eingegeben werden, die durch 8 teilbar ist!")
    splits = [eingabe_bin[x:x + 8] for x in range(0, len(eingabe_bin), 8)]  # list comprehension
    for item in range(0, len(splits)):
        dual = int(splits[item], 2)
        uni_code = chr(dual)
        print(uni_code, end="")

except Exception as e:
    print("Es ist etwas schiefgelaufen! \n", e)
    