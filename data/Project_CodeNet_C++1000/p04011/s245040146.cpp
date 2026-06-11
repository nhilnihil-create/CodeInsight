/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int n,k,x,y,total;
    cin >>n>>k>>x>>y; 
    if(n>k){
        total=((k*x)+((n-k)*y));
    }
    else{
        total=n*x;
    }
    printf("%d",total);
    
    
}
