import math

print("{")
for i in range(11):
    next = (i + 1) % 11
    print(math.cos((2 * i * math.pi) / 6), ",", 0.0, ",", math.sin((2 * i * math.pi) / 6), ",")
    print(math.cos((2 * next * math.pi) / 6), ",", 0.0, ",", math.sin((2 * next * math.pi) / 6), ",")
    print("0.0, 1.0, 0.0,")


print("}")
