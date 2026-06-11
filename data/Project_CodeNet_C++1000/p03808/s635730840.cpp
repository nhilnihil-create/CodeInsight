#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll N;
    cin >> N;
    ll sum = 0;
    vector<ll> A(N+1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    A[N] = A[0];
    if (sum % (N*(N+1)/2) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    ll op = sum / (N*(N+1)/2);
    for (int i = 1; i <= N; i++) {
        if ((A[i-1]-A[i]+op) % N != 0 || A[i] < op) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}