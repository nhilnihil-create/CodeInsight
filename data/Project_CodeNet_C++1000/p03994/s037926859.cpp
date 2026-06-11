#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
string alpha = "abcdefghijklmnopqrstuvwxyz";
int main(){
  string s; cin >> s;
  int k; cin >> k;
  rep(i, s.size()){
    if (s[i] == 'a') continue;
    if ('z'-s[i]+1 <= k){
      k -=('z'-s[i] + 1);
      s[i] = 'a';
    }
  }
  s[s.size()-1] = alpha[(s[s.size()-1]-'a'+k)%26];
  cout << s << endl;
}