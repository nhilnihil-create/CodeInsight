#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;
int main(){
   int n;
   cin >> n;
   ll ans=1;
   map<int,int> m;
   for (int t=1;t <= n;t++){
     int tmp;
     tmp=t;
    for (int i=2;i*i <= t;i++){
     while(tmp%i==0){
       if (tmp%i==0){
         m[i]++;
         tmp/=i;
       }
      }
    }
    if (tmp != 1) m[tmp]++;
   }
   for (auto q:m){
     //printf("q.first : %d q.second : %d\n",q.first, q.second);
     ans*=(ll)(q.second +1);
     ans%=mod;
   }
   cout << ans << endl;


   return 0;
}

