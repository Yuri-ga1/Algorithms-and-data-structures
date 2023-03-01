#include <iostream>
#include <chrono>
#include <math.h>
#include <string.h>
#include <map>

std::map <int, int> dict;

float memory_allocation(int n);

int main(){
    std::string str;
    for(int i=0; i<=4; i++){
        int degree = pow(10,i);
        str.append(std::to_string(degree));
        str.append(" ");
        str.append(std::to_string(memory_allocation(i)));
        str.append(" ");
    }
    str.pop_back();
    std::cout<<str;
    //std::cin>>str;
    return 0;
}

float memory_allocation(int n){
    int degree = pow(10,n);
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int j=0; j<degree; j++){
        dict.insert({j,j});
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> elapsed = t2 - t1;
    return elapsed.count();
}