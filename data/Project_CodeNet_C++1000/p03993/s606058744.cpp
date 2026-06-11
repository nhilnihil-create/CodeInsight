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
   VI a(n);
   rep(i,n)cin >> a.at(i);
   int ans=0;
   rep(i,n){
      if(a.at(a.at(i)-1)==i+1)ans++;
   }
   cout << ans/2 << endl;
}