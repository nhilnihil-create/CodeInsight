#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    long long N;
    cin >> N;
    vector<long long> A(N * 3);
    vector<long long> S1(N + 1, 0);
    vector<long long> S2(N + 1, 0);
    for(int i = 0; i < 3 * N; i++)cin >> A[i];
    priority_queue<ll, vector<ll>, greater<ll>> M;
    priority_queue<ll> m;
    
    for(int i = 0; i < 2 * N; i++){
        if(i < N){
            S1[0] += A[i];
            M.push(A[i]);
        }else{
            S1[i + 1 - N] = S1[i - N] + A[i];
            M.push(A[i]);
            S1[i + 1 - N] -= M.top();
            M.pop();
        }
    }
    
    reverse(A.begin(), A.end());
    
    for(int i = 0; i < 2 * N; i++){
        if(i < N){
            S2[0] += A[i];
            m.push(A[i]);
        }else{
            S2[i + 1 - N] = S2[i - N] + A[i];
            m.push(A[i]);
            S2[i + 1 - N] -= m.top();
            m.pop();
        }
    }
    
    reverse(S2.begin(), S2.end());
    
    long long ans = -1e15;
    for(int i = 0; i <= N; i++){
        ans = max(ans, S1[i] - S2[i]);
    }
    cout << ans << endl;
    return 0;
}