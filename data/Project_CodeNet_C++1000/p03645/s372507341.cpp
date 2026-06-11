#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  int N, M; cin >> N >> M;
  vector<int> A(N+1,0);
  int a, b;
  rep(i,M) {
    cin >> a >> b;
    if (a==1) A[b]++;
    else if (b==N) A[a]++;
  }

  int idx = find(all(A), 2) - A.begin();
  if (idx==N+1) cout << "IMPOSSIBLE" << endl;
  else cout << "POSSIBLE" << endl;
  
  // cout << fixed << setprecision(10);
  
  return 0;
}

