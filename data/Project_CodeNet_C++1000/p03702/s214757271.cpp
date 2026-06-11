#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll N, A, B;
ll H[101010];

ll ng = 0, ok = 1000000000LL;

bool check(ll p){
    ll al = B * p;
    ll tmp = A - B;
    for(ll i = 0; i < N; i++){
        ll h = H[i] - al;
        if(h > 0){
            ll hoge = (h + (tmp - 1)) / tmp;
            p -= hoge;
        }
        if(p < 0)return false;
    }
    return true;
}

int main(){
    
    cin >> N >> A >> B;
    for(ll i = 0; i < N; i++)cin >> H[i];
    while(ng + 1 < ok){
        ll p = (ng + ok) / 2;
        bool flg = check(p);
        if(flg)ok = p;
        else ng = p;
    }
    cout << ok << endl;
    
    return 0;
}
