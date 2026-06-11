#include <bits/stdc++.h>
using namespace std;
#include <math.h>

int main() {
 int W,a,b;
 cin>>W>>a>>b;
 if(abs(b-a)<=W){cout<<0<<endl;}
 else {cout<<abs(b-a)-W<<endl;}

 return 0;}