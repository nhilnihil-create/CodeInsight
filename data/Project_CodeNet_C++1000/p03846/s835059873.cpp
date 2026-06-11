#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

ll f(int n){
    ll res = 1;
    while(n--){
        res = (res * 2)%MOD;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    if(n%2){
        ll ans = 0;
        vi a((n+1)/2);
        rep(i,n){
            int b;
            cin >> b;
            b /= 2;
            a[b]++;
        }
        if(a[0]>=2){
            cout << 0 << endl;
            return 0;
        }
        for(int i=1;i<a.size();i++){
            if(a[i]!=2){
                cout << 0 << endl;
                return 0;
            }
        }
        cout << f((n+1)/2-1) << endl;
    }else{
        vi a(n/2);
        rep(i,n){
            int b;
            cin >> b;
            b /= 2;
            a[b]++;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=2){
                cout << 0 << endl;
                return 0;
            }
        }
        cout << f(n/2) << endl;
    }
}