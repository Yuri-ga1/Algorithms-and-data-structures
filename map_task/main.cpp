#include <iostream>
#include <chrono>
#include <map>

map <int, int> dict;

float memory_allocation(int n);

int main(){
    for(int i=0; i<=8; i++){
        memory_allocation(i);
    }
    return 0;
}

float memory_allocation(int n ){
    int degree = pow(10,n);
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int j=0; j<degree; j++){
        mp.insert({j,j});
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> elapsed = t2 - t1;
    std::cout << elapsed.count()<< "ms\n";
    return elapsed;
}