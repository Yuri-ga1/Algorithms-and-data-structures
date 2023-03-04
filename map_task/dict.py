import time

def memory_allocation(n: int) -> float:
    t = time.perf_counter()
    dict = {i: i for i in range(n)}
    elapsed = (time.perf_counter()-t)
    return elapsed

mylist = []

for i in range(0,6):
    n=10**i
    elapsed = memory_allocation(n)
    mylist.append(n)
    mylist.append(elapsed)
    
print(mylist)