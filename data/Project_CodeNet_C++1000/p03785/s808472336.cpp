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
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];

    ll bus = 0;
    int r = 0, l = 0;
    sort(t.begin(), t.end());
    while(l < n){
        ll pass = 0;
        while(t[l] + k >= t[r] && r < n && pass+1 <= c){
            r++;
            pass++;
        }
        bus++;
        // cout << "l r bus" << l << r << bus << endl;
        l = r;
    }

    cout << bus << endl;
    return 0;
}
