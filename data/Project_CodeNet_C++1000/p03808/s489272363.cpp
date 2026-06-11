#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);


   int n;
   cin>>n;
   ll a[n];
   ll sum=0;
   ll t = 0;
   for(int i=0;i<n;i++){
       cin>>a[i];
       sum+=a[i];
       t += i+1;
   }
   if(sum%t){
       cout<<"NO"<<endl;
       return 0;
   }
   ll k = sum/t;
   ll cnt = 0;
   for(int i=0;i<n;i++){
       ll s = a[(i+1)%n] - a[i];
       //cerr<<i<<endl;
       if(a[i]<k){
           cout<<"NO"<<endl;
           return 0;
       }
       if(s==k) continue;
       else{
           s = k-s;
           if(s%n){
               cout<<"NO"<<endl;
               return 0;
           }
           else cnt += s/n;
       }
   }
   //cerr<<cnt<<endl;

   if(cnt>k){
       cout<<"NO"<<endl;
       return 0;
   }
   cout<<"YES"<<endl;
}