#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP2(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define INF 2e9
typedef long long ll;

int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>> p(n);
  REP(i,n){
    int a,b;
    cin>>a>>b;
    p[i]=make_pair(a,b);
  }
  sort(ALL(p),greater<pair<int,int>>());
  cout<<p[0].first+p[0].second<<endl;
	return 0;
}