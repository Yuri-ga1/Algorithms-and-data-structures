import matplotlib.pyplot as plt
    
quantity=input()
if (quantity.find('[', 0, 2)==0):
    is_python = True
    plt.title("python dict")
    quantity = quantity.replace('[', '')
    quantity = quantity.replace(']', '')
    quantity = quantity.replace(',', '')
else:
    is_python = False
    plt.title("С++ map")

quantity = quantity.split(" ")

x=[]
y=[]

for i in range(0, len(quantity), 2):
    x.append(int(quantity[i]))
    y.append(float(quantity[i+1]))

plt.xlabel("amount of elements")
plt.ylabel("filling time (ms)")
plt.plot(x,y)
plt.show()

y=[]
if(is_python):
    plt.title("python dict")
    plt.ylabel("need for memory (kilobytes)")

    for i in range(0, len(quantity), 2):
        y.append(float(quantity[i])/256)
else:
    plt.title("С++ map")
    plt.ylabel("need for memory (kilobytes)")

    for i in range(0, len(quantity), 2):
        y.append(float(quantity[i])/256)

plt.xlabel("amount of elements")
plt.plot(x,y)
plt.show()