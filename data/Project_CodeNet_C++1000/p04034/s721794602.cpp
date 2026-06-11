#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<utility>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;
ll gcd(int a, int b){return b ? gcd(b, a%b) : a;}
ll lcm(int a, int b){return a*b / gcd(a, b);}
const ll MAX = 1e9+7;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
    }

    vector<int> cnt(n, 1);
    vector<bool> red_in(n, false);
    red_in[0] = true;
    for(int i = 0; i < m; i++){
        if(red_in[x[i]-1] == true){
            red_in[y[i]-1] = true;
        }
        cnt[x[i]-1]--;
        cnt[y[i]-1]++;
        if(cnt[x[i]-1] == 0){
            red_in[x[i]-1] = false;
        }
    }
        
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(red_in[i] == true) ans++;
    }
    cout << ans << endl;
    return 0;
}
