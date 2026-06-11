#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
const int N =1e2;
int a,b,c;
int main(){
     scanf("%d %d %d",&a,&b,&c);
     printf("%d\n",((a+b)*c)/2);
}
