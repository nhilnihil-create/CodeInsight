#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(int N, map<ll, ll> const &dict, ll &ans){

    for(auto p: dict){
        auto value = p.second;

        if(value%2 != 0) ++ans;
    }

    return;
}

int main(){

    int N;
    cin >> N;
    map<ll, ll> dict;
    for(int i = 0; i != N; ++i){
        int tmp;
        cin >> tmp;
        ++dict[tmp];
    }

    ll ans{};
    solver(N, dict, ans);

    cout << ans << endl;

    return 0;
}