#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
// typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 998244353;
const lli e3 = 1 << 12;

lli n,m;
lli a[e3][e3];

bool solve(lli x){
  set<lli> s;
  queue<lli> b[e3];
  for(lli i = 0;i < n;i++){
    for(lli j = 0;j < m;j++){
      b[i].push(a[i][j]);
    }
  }

  for(lli i = 0;i < m;i++){
    lli cnt[e3];
    for(lli j = 0;j < m;j++){
      cnt[j] = 0;
    }
    for(lli j = 0;j < n;j++){
      cnt[b[j].front()]++;
    }
    lli flag = 0;
    for(lli j = 0;j < m;j++){
      if(cnt[j] > x){
        s.insert(j);
        for(lli k = 0;k < n;k++){
          while(!b[k].empty() && s.count(b[k].front())) b[k].pop();
        }
        flag = 1;
        break;
      }
    }
    if(flag == 0) return true;
  }
  return false;
}

int main(){
  cin >> n >> m;
  for(lli i = 0;i < n;i++)
    for(lli j = 0;j < m;j++) cin >> a[i][j];
  for(lli i = 0;i < n;i++)
    for(lli j = 0;j < m;j++) a[i][j]--;
  lli top = n;
  lli bottom = 0;
  while(top-bottom > 1){
    lli middle = (top+bottom)/2;
    if(!solve(middle)) bottom = middle;
    else top = middle;
  }
  cout << top << endl;
}
