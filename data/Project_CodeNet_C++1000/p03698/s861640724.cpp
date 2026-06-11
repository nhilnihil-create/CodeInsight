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
  sort(All(s));
  for(int i=0;i<s.size()-1;i++){
    if(s[i]==s[i+1]){
      cout<<"no\n";
      return 0;
    }
  }
  cout<<"yes\n";

  return 0;
}
