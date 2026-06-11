#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
   int  n;
   string s,t;
   cin >> n >> s >> t;
   int ans=2*n;
   rep(i,n){
       bool a=true;
       rep(j,n-i){
           if(s.at(i+j)!=t.at(j))a=false;
       }
       if(a){
           ans-=(n-i);
           break;
       }
   }
   cout << ans << endl;
} 

    