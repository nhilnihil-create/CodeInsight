#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
const ll INF = 1e16;

void solver(ll N, ll A, ll B, ll &ans){

    if(A > B) ans = 0;
    else if(N == 1){
        if(A == B) ans = 1;
        else ans = 0;
    }
    else{
        ll min_sum{}, max_sum{};
        min_sum = A + B + A*(N-2);
        max_sum = A + B + B*(N-2);
        ans = max_sum - min_sum + 1;
    }
    return;
}

int main(){

    ll N, A, B;
    cin >> N >> A >> B;

    ll ans{};
    solver(N, A, B, ans);

    cout << ans << endl;
    return 0;
}