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
    int x,a,b;
    cin >>  x >> a >> b;
    if(b-a<=0){
        printf("delicious");
    }
    else if(b-a>x){
        printf("dangerous");
    }
    else{
        printf("safe");
    }
}

