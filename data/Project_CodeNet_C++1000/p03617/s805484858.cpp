        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  998244353;
const int  Inv2 = (MOD+1)/2;

     signed main(){
  int q,h,s,d,n;cin>>q>>h>>s>>d>>n;
  h=min(2*q,h);s=min(2*h,s);d=min(d,2*s);cout<<(n/2)*d+(n%2)*s<<endl;

         
}

        
