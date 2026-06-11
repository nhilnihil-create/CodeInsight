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
typedef pair<int, int> Pi;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];

    vector<bool> one2i(n+1, false);
    vector<bool> i2n(n+1, false);
    for(int i = 0; i < m; i++){
        if(a[i] == 1){
            one2i[b[i]] = true;
        }
    }
    for(int i = 0; i < m; i++){
        if(b[i] == n){
            i2n[a[i]] = true;
        }
    }

    string ans = "IMPOSSIBLE";
    // cout << ans << endl;
    for(int i = 2; i < n; i++){
        if(one2i[i] == true && i2n[i] == true){
            ans = "POSSIBLE";
        }
    }

    cout << ans << endl;
    return 0;
}
