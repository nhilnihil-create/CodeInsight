#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

vector<ll> prime_factor(ll num){
    vector<ll> vec;
    ll a = 2;
    while(num >= a*a){
        if(num%a==0){
            vec.push_back(a);
            num /= a;
        }else{
            a++;
        }
    }
    vec.push_back(num);
    return vec;
}

map<int, int> mp;
int main() {
    cin >> N;
    for(int i=2;i<=N;i++){
        vector<ll> vec = prime_factor(i);
        rep(i, vec.size()){
            if(mp.find(vec[i]) == mp.end()) mp[vec[i]] = 1;
            else mp[vec[i]]++;
        }
    }
    ll sum = 1;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        sum = (sum * (itr->second+1))%MOD;
    }
    cout << sum;
}
