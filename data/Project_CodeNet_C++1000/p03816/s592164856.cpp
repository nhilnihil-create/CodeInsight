#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;

    vector<ll> A(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end());

    ll cnt = 0;

    for(ll i=1; i<N; i++){
        if(A[i-1] == A[i]){
            cnt += 1;
        }
    }

    if(cnt%2==0){
        cout << N - cnt << endl;
    }
    else{
        cout << N - cnt - 1 << endl;
    }

    return 0;
}
