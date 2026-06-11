#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

vector<ll> imos, A;
ll N, M;

void init(){
    cin >> N >> M;
    imos.resize(M);
    A.resize(N);
    for(ll &a : A){
        cin >> a;
        a--;
    }
}

void set_imos(){
    vector<P> v;
    for(ll i = 0; i < N - 1; i++){
        if(A[i] < A[i + 1]){
            v.push_back(P(A[i + 1], A[i + 1] - A[i]));
            imos[A[i + 1]]--;
            imos[A[i]]++;
        }else{
            v.push_back(P(M - 1, M - 1 - A[i]));
            imos[M - 1]--;
            imos[A[i]]++;
            v.push_back(P(A[i + 1], (M - 1 - A[i]) + A[i + 1] + 1));
            imos[A[i + 1]]--;
        }
    }
    for(ll i = M - 1; i > 0; i--) imos[i - 1] += imos[i];
    for(const auto &p : v) imos[p.first] += p.second;
    for(ll i = M - 1; i > 0; i--) imos[i - 1] += imos[i];
}

ll solve(){
    init();
    set_imos();
    ll ret = 0;
    for(ll i = 0; i < N - 1; i++){
        if(A[i + 1] > A[i]){
            ret += A[i + 1] - A[i];
        }else{
            ret += (M - 1) - A[i];
            ret++;
            ret += A[i + 1];
        }
    }
    return ret - *max_element(imos.begin(), imos.end());
}


int main(){
    cout << solve() << endl;
    return 0;
}
