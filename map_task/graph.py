import matplotlib.pyplot as plt

quantity=int(input())
x=[]
y=[]

for i in range(quantity):
    x.append(int(input()))
    y.append(float(input()))

plt.plot(x,y)
plt.show()