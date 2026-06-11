#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define numrep(i,n) for(int i=1;i<=n;i++)
#define bitrep(n) for(int bit=0;bit<(1<<n);bit++)
#define ll int64_t
#define all(v) v.begin(), v.end()

const int MOD = 1000000007;

int main() {

int N; cin >> N ;

vector<int> A(N); rep(i,N) cin >> A[i];

map<int,int> M;

rep(i,N) M[A[i]]++;

stack<int> S;

for(auto p : M){
  int key=p.first;
  int value=p.second;
  while(value>=2){
    S.push(key);
    value-=2;
  }
}

ll ans;

if(S.size()<=1) ans=0;

else{
int x=S.top();
S.pop();
int y=S.top();

ans=(ll)x*y;
}

cout << ans << endl;

return 0;
}