#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

vector<pair<ll,ll>> factorize(ll N){
    ll n = N;
    vector<pair<ll,ll>> v;
    for(ll i = 2; i*i<=n; i++){
        if(n % i != 0)continue;
        v.push_back(make_pair(i,0));
        while(n % i == 0){
            v.back().second++;
            n /= i;
        }
    }
    if(n != 1)v.push_back(make_pair(n,1));
    return v;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> memo(N+1,0);
    rep(i,N){
        auto v = factorize(i+1);
        rep(j,v.size()){
            memo[v[j].first] += v[j].second;
        }
    }

    ll tot = 1;
    for(auto& e:memo){
        tot *= (e+1);
        tot %= mo;
        //cout << e << " ";
            
    }
    //cout << endl;

    cout << tot << endl;

}
/*
 1  2 3 4
24 12 8 6

1    2  3  4  5  6  8 10
120 60 40 30 24 20 15 12

1   2   3   4   5   6   8  9  10 12 15 16 18 20 24
720 360 240 180 144 120 90 80 72 60 48 45 40 36 30
*/