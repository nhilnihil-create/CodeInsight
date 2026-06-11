#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

vector<bool> pushed(100005, false);
vector<int> a;
int N;
int ans = -1;

void dfs(int button, int count=0){
    if (pushed[button]) return;
    if (button == 1) {
        ans = count; return;
    }
    pushed[button] = true;
    dfs(a[button], count+1);

}

int main(){
    cin >> N;
    a.assign(N, 0);
    rep(i,N) {
        int b; 
        cin >> b;
        a[i] = --b;    
    }
    dfs(0);

    cout << ans << endl;
}