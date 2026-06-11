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

int main(){
    int n;
    ll L;
    cin >> n >> L;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int id = -1;
    rep(i,n-1){
        if(a[i]+a[i+1]>=L){
            id = i;
            break;
        }
    }
    if(id==-1){
        cout << "Impossible" << endl;
        return 0;
    }else{
        cout << "Possible" << endl;
    }

    for(int i=0;i<id;i++){
        cout << i+1 << endl;
    }
    for(int i=n-2;i>=id;i--){
        cout << i+1 << endl;
    }


    return 0;
}