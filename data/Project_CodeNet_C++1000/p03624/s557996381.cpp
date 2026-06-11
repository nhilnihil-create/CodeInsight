#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  string s;
  cin>>s;
  vector<bool> ch(26);
  for(int i=0;i<(int)s.size();i++){
    ch[s[i]-'a']=true;
  }

  for(int i=0;i<26;i++){
    if(!ch[i]){
      cout<<(char)('a'+i)<<"\n";
      return 0;
    }
  }
  cout<<"None\n";

  return 0;
}
