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

struct SegmentTree{
  vector <int> Tree[20];
  void Make(){
    for (int i = 0; i < 20; i++){
      Tree[i].resize(1<<i);
    }
  }

  void Add(int num, ll val){
    for (int i = 19; i >= 0; i--){
      Tree[i][num] += val;
      num /= 2;
    }
  }

  ll Count(int num){
    int now = 19; 
    ll ans = Tree[now][num];
    while (now > 0 && num > 0){
      if (num % 2 != 0){
        num--;
      }else{
        now--; num /= 2; num--;
      }
      ans += Tree[now][num];
    }
    return ans;
  }

};

int N; ll K;
ll A[int(2e5+5)], sum[int(2e5+5)];
map <ll, int> Index;

void Make_Index(){
  map <ll, bool> used;
  vector <ll> now;
  for (int i = 0; i <= N; i++){
    if (used[sum[i]]) continue;
    used[sum[i]] = true;
    now.push_back(sum[i]);
  }
  sort(now.begin(), now.end());
  for (int i = 0; i < now.size(); i++){
    Index[now[i]] = i;
  }
}

int main(){
  cin >> N >> K;
  for (int i = 1; i <= N; i++){
    cin >> A[i];
    sum[i] = sum[i-1] + A[i];
  }
  for (ll i = 0; i <= N; i++){
    sum[i] -= i * K;
  }
  Make_Index();
  for (int i = 0; i <= N; i++){
    sum[i] = Index[sum[i]];
  }

  SegmentTree Tree; Tree.Make();
  ll ans = 0;
  for (int i = 0; i <= N; i++){
    ans += Tree.Count(sum[i]);
    Tree.Add(sum[i], 1);
  }
  cout << ans << endl;

  return 0;
}
