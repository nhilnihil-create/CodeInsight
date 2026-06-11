/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int a,b,x,abs1,abs2;
    cin>>x>>a>>b;
    if(a-x>=0){
        abs1= a-x;
    }
    else{
        abs1= -(a-x);
    }
    if(b-x>=0){
        abs2= b-x;
    }
    else{
        abs2=-(b-x);
    }
    if(abs1>abs2){
        printf("B");
    }
    else{
        printf("A");
    }
}
