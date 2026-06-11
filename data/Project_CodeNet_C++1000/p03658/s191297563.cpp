#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 int n,k;
 cin >> n >> k;
 VI l(n);
 rep(i,n)cin >> l[i];
 sort(l.begin(),l.end());
 reverse(l.begin(),l.end());
 int ans=0;
 rep(i,k){
    ans+=l.at(i);
 }
  cout << ans << endl;
}

