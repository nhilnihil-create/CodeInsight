#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++){ ;
int main() {
   int a,b,c;
   cin>>a>>b>>c;
   if((a+b+c)%2==0){
   int d=(a+b+c)/2;
   if(a==d||b==d||c==d){
       cout<<"Yes"<<endl;
   }
   else
   cout<<"No"<<endl;
   }
   else
   cout<<"No"<<endl;
}
