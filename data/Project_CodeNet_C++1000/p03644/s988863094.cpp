#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int cnt(int x){
    int res = 0;
    while(x%2 == 0){
        x /= 2;
        ++res;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int mx = 0;
    int ans = 1;
    for(int i=1;i<=n;i++){
        int mm = cnt(i);
        if(mm > mx){
            mx = mm;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}