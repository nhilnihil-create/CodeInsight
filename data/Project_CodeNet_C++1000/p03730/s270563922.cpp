#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   int a,b,c,m; cin>>a>>b>>c;m=a;
   int p=100000;
   while(a<p){
    if(a%b==c){cout<<"YES";return 0;}
    else a=a+m;
   }
   cout<<"NO";
}
