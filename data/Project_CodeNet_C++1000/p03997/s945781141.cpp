#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int min(int a,int b){
    return (a<b) ? a : b ;
}

int max(int a,int b){
    return (a<b) ? b : a ;
}


int main() {

    int a,b,h ;
    cin >>a>>b>>h  ;

    cout << (a+b)*h*0.5 << endl ;

 return 0 ;
}  
