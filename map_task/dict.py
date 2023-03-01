#import matplotlib.pyplot as plt
import time

def memory_allocation(n: int) -> float:
    t = time.perf_counter()
    dict = {i: i for i in range(n)}
    elapsed = time.perf_counter()-t
    #print(f"Elpased time {elapsed}ms")
    return elapsed

x=[]
y=[]

for i in range(0,5):
    n=10**i
    elapsed = memory_allocation(n)
    x.append(n)
    y.append(elapsed)
    
print(len(x))

for i in range(len(x)):
    print(x[i])
    print(y[i])
#plt.plot(x,y)
#plt.show()
