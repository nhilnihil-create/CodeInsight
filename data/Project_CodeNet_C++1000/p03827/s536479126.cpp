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
   int x=0;
   string s;
   cin >> s;
   int ans=0;
   rep(i,n){
      if(s.at(i)=='I')x++;
      else if(s.at(i)=='D')x--;
      ans=max(ans,x);
   }
   cout << ans << endl;
}