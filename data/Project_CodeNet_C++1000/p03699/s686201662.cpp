#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}
using namespace std;

int main(){
   int n;
   cin>>n;
   
   vector<int> a(n,0);
   ll sum=0;
   rep(i,n){
      cin>>a[i];
      sum+=a[i];
   }
   sort(a.begin(),a.end());

   rep(i,n){
      if(sum%10!=0) {
         cout<<sum;
         return 0;
      }
      else {
         bool f=false;
         rep(j,n){
            if(a[j]%10!=0){
               sum-=a[j];
               f=true;
               break;
            }
         }
         if(f==false) {
            sum=0;
            cout<<sum;
            return 0;
         }
      }
      }
return 0;
}

