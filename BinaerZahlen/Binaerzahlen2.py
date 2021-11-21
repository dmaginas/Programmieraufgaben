inp = input("Binärzahl: ")
print("".join([chr(int(inp[i:i+8], base=2)) for i in range(0, len(inp), 8)]))
