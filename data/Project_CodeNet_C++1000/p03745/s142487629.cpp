#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}



int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, r = 0, l = 0;
    for(int l = 0; l < n; l++){
        if(l == r){
            int increase_r = r, decrease_r = r;
            
            while(increase_r+1 < n && a[increase_r] <= a[increase_r+1]){ //等値or増加
                increase_r++;
            }
            while(decrease_r+1 < n && a[decrease_r] >= a[decrease_r+1]){ //等値or減少
                decrease_r++;
            }
            ans++;
            // cout << "increase: " << increase_r << " decrease: " << decrease_r << endl;
            r = max(increase_r, decrease_r)+1;
            // cout << "right: " << r << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
