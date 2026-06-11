#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<ll> S(N);
    ll sum = 0;
    for(int i=0; i<N; i++) {
        cin >> S[i];
        sum += S[i];
    }
    sort(S.begin(), S.end());

    for(int i=0; i<N; i++) {
        if(sum % 10 == 0 && S[i] % 10 != 0) {
            sum -= S[i];
        }
        if(sum % 10 != 0) {
            break;
        }
    }
    if(sum % 10 == 0) sum = 0;
    cout << sum << endl;

}