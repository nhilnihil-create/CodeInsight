#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int N,M;
  cin >> N >> M;
  vector<int> vec(N,0);
  vector<P> A(M);
  REP(i,M){
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    A[i].second--;
    vec.at(A[i].first)++;
    vec.at(A[i].second)--;
  }
  
  int sum = 0;
  vector<int> ans(N);
  REP(i,N){
    sum+=vec.at(i);
    ans.at(i)=sum;
  }

  int flag=0;
  REP(i,N){
    if(ans.at(i)%2==1){
      flag=1;
    }
  }

  if(flag==0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}