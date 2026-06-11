#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int N;
   cin>>N;
   int a[N];
   for(int i=0;i<N;i++){
       cin>>a[i];
   }
   int count=0;
   for(int i=0;i<N;i++){
    if(a[a[i]-1]-1==i){count++;}
   }
   cout<<count/2<<endl;
return 0;}