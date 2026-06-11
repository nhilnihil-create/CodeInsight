/**
*    author:  yuya1234
*    created: 14.07.2020 10:43:39
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  vector<string> v;
  string tmp;
  REP(i,3){
    cin>>tmp;
    v.emplace_back(tmp);
  }

  int idx=0;
  char card;
  for(;;)
  {
    card=v[idx][0];
    if(SZ(v[idx])>1)v[idx]=v[idx].substr(1);
    else if(SZ(v[idx])==1)v[idx]="";
    else break;
    if(card=='a')idx=0;
    else if(card=='b')idx=1;
    else idx=2;
  } 

  cout<<(char)('A'+idx)<<endl;
  return 0;
}