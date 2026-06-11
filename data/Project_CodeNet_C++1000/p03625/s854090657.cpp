#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int n;
   cin >> n;
   vector<ll> a(n);
   rep(i,n){
       cin >> a.at(i);
   }
   ll ans1=0;
   ll ans2=1;
   sort(a.begin(),a.end());
   reverse(a.begin(),a.end());
   rep(i,n-3){
       if(a.at(i)==a.at(i+3)){
           ans1=a.at(i)*a.at(i+3);
           break;
       }
   }
    int cnt=0;
    set<ll> chk;
   rep(i,n-1){
       if(a.at(i)==a.at(i+1)){
           if(chk.count(a.at(i))){
           }
           else{
            ans2*=a.at(i);
            chk.insert(a.at(i));
            cnt++;   
           }
       }
       if(cnt>=2)break;
       if(i==n-2 && cnt<=1)ans2=0;
   }
   ll ans=max(ans1,ans2);
   cout << ans << endl;
}