import time
import sys

def memory_allocation(n: int) -> float:
    t = time.perf_counter()
    dict = {i: i for i in range(n)}
    elapsed = (time.perf_counter()-t)
    return elapsed, dict

mylist = []

for i in range(0,6):
    n=10**i
    elapsed, dict = memory_allocation(n)
    mylist.append(n)
    mylist.append(elapsed)
    mylist.append(sys.getsizeof(dict))
    
print(mylist)
