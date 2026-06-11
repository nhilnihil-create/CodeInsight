#include <bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

int main(){
    int N;  cin >> N;
    vector<vector<ll>> A, D;
    A = vector<vector<ll>>(N, vector<ll>(N));
    D = vector<vector<ll>>(N, vector<ll>(N));
    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        cin >> A[i][j];
        D[i][j] = A[i][j];
    }
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++) for(int j=0; j<N; j++){
            if(D[i][j] > D[i][k] + D[k][j]){
                D[i][j] = D[i][k] + D[k][j];
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<N; i++) for(int j=i; j<N; j++){
        bool flag = true;
        for(int k=0; k<N; k++){
            if(i==k || j==k) continue;
            if(D[i][k] + D[k][j] < A[i][j]){
                cout << -1 << endl;
                return 0;
            }else if(D[i][k] + D[k][j] == A[i][j]){
                flag = false;
            }
        }
        if(flag) ans += A[i][j];
    }
    cout << ans << endl;
}
