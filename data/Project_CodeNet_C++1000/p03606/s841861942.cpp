#include <bits/stdc++.h>
using namespace std;
#include <math.h>

int main() {
 int N;
 cin>>N;
 int sum=0;
 int l,r;
 while(cin>>l>>r){
     sum+=r-l+1;
 }
 cout<<sum<<endl;
 return 0;}