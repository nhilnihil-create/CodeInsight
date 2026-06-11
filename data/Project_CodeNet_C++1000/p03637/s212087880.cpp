#include<bits/stdc++.h>
using namespace std;
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

int main(){
   int n;
   cin>>n;

   vector<int> a(n);
   vector<int> c={0,0,0};

   rep(i,n){
      cin>>a[i];
      if(a[i]%4==0){
         c[2]++;
      }
      else if(a[i]%2==0){
         c[1]++;
      }
      else{
          c[0]++;
      }
   }

   if(c[1]==0){
      if(c[0]<=c[2]+1) cout<<"Yes";
      else cout<<"No";
   }
   else{
      if(c[0]<=c[2]) cout<<"Yes";
      else cout<<"No";
   }




   return 0;
}
