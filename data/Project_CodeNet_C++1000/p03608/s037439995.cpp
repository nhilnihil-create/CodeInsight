#include <bits/stdc++.h>

using namespace std;
const long long INF=1LL<<60;

int main(){
  long long n, m, R, d[209][209];
  vector<long long> r;
  cin >> n >> m >> R;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)d[i][j]=INF;
    d[i][i]=0;
  }
  for(int i=0;i<R;i++){
    long long rr;cin >> rr;
    rr--;
    r.push_back(rr);
  }
  for(int i=0;i<m;i++){
    long long a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    d[a][b] = c;
    d[b][a] = c;
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
  long long mn=INF;
  sort(r.begin(), r.end());
  do{
    long long sm=0;
    for(int i=0;i<R-1;i++)sm+=d[r[i]][r[i+1]];
    mn = min(mn , sm);
  }while(next_permutation(r.begin(), r.end()));
  cout << mn << endl;
}

