#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(t) (t).begin(),(t).end()
typedef long long ll;

int main() {
  int Ans=0;
  int N; cin>>N;
  vector<int> a(N);
  REP(i,N){
    cin>>a.at(i);
    a.at(i)--;
  }
  REP(i,N){
    if (i==a.at(a.at(i)))  Ans++;
  }
  cout << Ans/2 << '\n';
  return 0;
}
