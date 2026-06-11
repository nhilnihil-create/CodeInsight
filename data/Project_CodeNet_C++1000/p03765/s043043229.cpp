#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

string S, T;
int s[int(1e5+5)], t[int(1e5+5)];

int main(){
  cin >> S >> T;
  for (int i = 1; i <= S.length(); i++){
    s[i] = s[i-1];
    if (S[i-1] == 'A') s[i]++;
    else s[i] += 2;
  }

  for (int i = 1; i <= T.length(); i++){
    t[i] = t[i-1];
    if (T[i-1] == 'A') t[i]++;
    else t[i] += 2;
  }


  int Q; cin >> Q;
  for (int i = 0; i < Q; i++){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int nows = s[B] - s[A-1], nowt = t[D] - t[C-1];

    if ((nowt - nows) % 3 == 0) YES();
    else NO();
  }

  return 0;
}
