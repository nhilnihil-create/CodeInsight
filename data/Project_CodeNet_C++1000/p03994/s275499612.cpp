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
  string s;
  cin >> s;
  int K;
  cin >> K;
  int N = s.size();
  REP(i,N){
    if(K>='z'-s.at(i)+1&&i!=N-1&&s.at(i)!='a'){
      K-='z'-s.at(i)+1;
      s.at(i)='a';
    }else if(i==N-1&&K>0){
      K=K%26;
      if(s.at(i)+K>'z'){
        s.at(i)='a'+K-('z'-s.at(i))-1;
      }else{
        s.at(i)=s.at(i)+K;
      }
    }
  }

  cout << s << endl;
}