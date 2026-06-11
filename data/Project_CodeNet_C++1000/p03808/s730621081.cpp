#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N;
ll A[100010];
ll d[100010];

int main(){

    cin >> N;
    ll tot = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        tot += A[i];
    }
    if(tot % (N*(N + 1) / 2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll k = tot / (N*(N + 1) / 2);
    for(int i = 0; i < N; i++){
        d[i] = A[(i + 1) % N] - A[i];
        d[i] -= k;
    }
    for(int i = 0; i < N; i++){
        if(d[i] <= 0 && abs(d[i]) % N == 0){
            k -= abs(d[i]) / N;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }

    if(k == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
