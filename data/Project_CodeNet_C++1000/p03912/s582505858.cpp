#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
using namespace std;

int solve(int an,int ap, int bn, int bp){
  int answer=0;
  REP(pairs,min(an,bn)+1)
    answer=max(answer,pairs+min(an-pairs,ap)/2+min(bn-pairs,bp)/2);
  return answer;  
}
int main(void)
{
  int n,m;
  cin >> n >> m;
  vector<int> bu(131072,0),bun(131072,0),bup(131072,0);
  REP(i,n){
    int x;
    cin >> x;
    bu[x]++;
  }
  REP(i,131072){
    bun[i%m]+=bu[i];
    bup[i%m]+=bu[i]/2*2;
  }
  int answer=bun[0]/2;
  if(m%2==0) answer+=bun[m/2]/2;
  for(int i=1;i*2<m;++i) answer+=solve(bun[i], bup[i], bun[m-i], bup[m-i]);
  cout << answer << endl;
  return 0;
}