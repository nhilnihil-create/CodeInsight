#include<iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a,int b){
    return (a<b) ? a : b ;
}

int main() {

int n,T ;
cin >> n >> T ;
int t[n] ;
for(int i=0;i<n;++i) cin >> t[i] ;

int s = T ;

if(n>1){
for(int i=1;i<n;++i)
{
    s+= min(t[i]-t[i-1],T) ;
} 
}

cout << s << endl ;

return 0 ;
}  