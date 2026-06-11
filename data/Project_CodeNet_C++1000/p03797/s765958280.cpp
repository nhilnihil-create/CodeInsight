#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(void){
   long long N,M;
   cin>>N>>M;
   long long temp=min(N,M/2);
   long long count=temp+(M-temp*2)/4;
   cout<<count<<endl;
   return 0;
}