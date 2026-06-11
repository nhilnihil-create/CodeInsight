#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

//INFの定義
const int INF = pow(10, 7);

//Nの約数を列挙したものを取得する関数
vector<ll> func(ll num){
    vector<ll> p;
    for(ll i = 1; i*i <= num; i++){
        if(num % i == 0) p.push_back(i);
    }
    return p;
}

//桁数を求める関数
int keta(int num){
    int k = 1;
    while(num / 10 != 0){
        num /= 10;
        k++;
    }
    return k;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> p = func(N);
    ll len = (ll)p.size();
    int mn = INF;
    rep(i, len){
        ll a = p[i];
        ll b = N / a;
        int val = keta(max(a, b));
        mn = min(mn, val);
    }
    cout << mn << endl;
    return 0;
}