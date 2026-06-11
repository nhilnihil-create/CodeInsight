#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(int N, ll C, ll K, vector<ll> &A, ll &ans){
    
    sort(A.begin(), A.end());

    ll sum{}, st_time = A.at(0);
    for( int i = 0; i < N; ++i ){
        if( A.at(i) > K+st_time ){
            ++ans;
            sum -= C;
            if( sum < 0 ){
                sum = 0;
            }
            st_time = A.at(i);
        }
        else if( sum >= C ){
            ++ans;
            sum -= C;
            st_time = A.at(i);
        }
        ++sum;
    }

    if( sum != 0){
        if( sum%C == 0 ){
            ans += sum/C;
        }
        else{
            ans += sum/C+1;
        }
    }
    return;
}

int main(){

    int N;
    ll C, K;
    cin >> N >> C >> K;
    vector<ll> A(N);
    for( int i = 0; i < N; ++i){
        cin >> A.at(i);
    }

    ll ans{};
    solver(N, C, K, A, ans);

    cout << ans << endl;
    return 0;
}
