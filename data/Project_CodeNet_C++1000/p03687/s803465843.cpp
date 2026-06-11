#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s;
  cin >> s;

  int n=s.size();
  int ans=1000;
  
  rep(i,n){
    char check = s.at(i);
    int maxstep = i;
    int last = i;
    for(int j=i; j<n; j++){
      if(s.at(j)==check){
        maxstep = max(maxstep, j-last-1);
        last = j;
      }
    }
    maxstep = max(maxstep, n-last-1);
    //cout << check << " "  << maxstep << " " << last << endl;
    ans = min(ans, maxstep);
  }

  cout << ans;
}