#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector< int > c;
vector< int > s;
map<int, int> mp;

int main(void){
  int n,m;
  cin >> n >> m;
  c.resize(m);
  s.resize(m);
  fill(c.begin(),c.end(),0);
  fill(s.begin(),s.end(),0);
  for(int i = 0;i < n;++i){
    int a;
    cin >> a;
    ++c[a % m];
    ++mp[a];
  }
  for(map<int, int>::iterator itr = mp.begin();
      itr != mp.end();++itr) {
    s[(itr->first) % m] += (itr->second)/2;
  }

  int res = 0;
  for(int i = 0;i < m;++i) {
    /*
    for(int j = 0;j < m;++j) {
      cout << c[j] << " ";
    }
    cout << endl;
    */
    int p;
    if(i != (m-i) % m){
      p = min(c[i],c[(m-i) % m]);
    } else {
      p = c[i]/2;
    }
    res += p;
    c[i] -= p;
    c[(m-i) % m] -= p;
  }
  /*
  for(int j = 0;j < m;++j) {
    cout << s[j] << " ";
  }
  cout << endl;
  */
  for(int i = 0;i < m;++i){
    res += min(s[i]*2, c[i]) / 2;
  }
  cout << res << endl;
  return 0;
}
