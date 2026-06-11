#include<iostream>
#include<algorithm>
typedef long long ll; 
using namespace std;
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
   ll p[3]={a,b,c};
   sort(p,p+3);
   if(p[2]%2==0){
       cout<<0<<endl;
   }
   else
   {
       ll sum=p[1]*p[0];
       cout<<sum<<endl;
   }
   
}