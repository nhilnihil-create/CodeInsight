#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> Pii;
typedef pair<int, Pii> Pip;

string s;
int n;
char endc;
vector<int> p[26];
int pre[300010];

int dij() {
  bool used[n+10] = {0};
  queue<Pip> Q;
  for ( int i = 0; i < 26; i++ ) {
    if ( p[i].size() == 0 ) continue;
    Q.push(Pip(1, Pii(i*i, p[i][0])));    
    used[p[i][0]] = true;
  }

  while ( !Q.empty() ) {
    Pip q = Q.front(); Q.pop();
    int c = q.first, v = q.second.second;
    int u = q.second.first;

    //cout << v << endl;

    if ( v == n+1 ) {
      return c;
    }

    /*if ( v == 126 ) {
      cout << "ac";
    }
    if ( v == 85 ) {
      cout << "ba" << endl;
      }*/
    for ( int i = 0; i < 26; i++ ) {
      auto it = upper_bound(p[i].begin(), p[i].end(), v);
      if ( it == p[i].end() ) {
	if ( used[n+1] ) continue;
	used[n+1] = true;
	endc = 'a'+i;
	pre[n+1] = v;
	Q.push(Pip(c+1, Pii(i, n+1)));
      } else {
	if ( used[*it] ) continue;
	used[*it] = true;
	pre[*it] = v;
	Q.push(Pip(c+1, Pii(i, (int)(*it))));	
      }
    }
  }
}

signed main() {
  cin >> s;
  n = s.size();
  for ( int i = 0; i < n; i++ ) {
    p[s[i]-'a'].push_back(i);
    //if ( s[i] == 'c' ) cout << i << " ";
  }
  //cout << endl;
  

  for ( int i = 0; i < 26; i++ ) {
    if ( p[i].size() == 0 ) {
      cout << (char)('a'+i) << endl;
      return 0;
    }
  }

  for ( int i = 0; i < 300001; i++ ) pre[i] = -1;

  int cost = dij();
  //cout << cost << endl;

  int now = n+1;
  string ans = "";
  while ( pre[now] != -1 ) {
    ans.push_back(s[pre[now]]);
    //cout << s[pre[now]] << " " << pre[now] << endl;
    now = pre[now];
  }

  for ( int i = ans.size()-1; i >= 0; i-- ) cout << ans[i];  
  cout << endc << endl;
  
  return 0;
}
