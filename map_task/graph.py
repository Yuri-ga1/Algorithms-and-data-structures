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
z=[]

for i in range(0, len(quantity), 3):
    x.append(int(quantity[i]))
    y.append(float(quantity[i+1]))
    z.append(float(quantity[i+2])/1024)

plt.xlabel("amount of elements")
plt.ylabel("filling time (ms)")
plt.plot(x,y)
plt.show()

if(is_python):
    plt.title("python dict")
else:
    plt.title("С++ map")

plt.ylabel("need for memory (kilobytes)")
plt.xlabel("amount of elements")
plt.plot(x,z)
plt.show()