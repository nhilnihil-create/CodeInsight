#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  string s; cin >> s;
  char now = s.at(0);
  int count = 1;
  for(int i=1;i<s.size();i++){
    if(s.at(i)!=now){
      count++;
      now = s.at(i);
    }
  }
  cout << count-1 << endl;
}
