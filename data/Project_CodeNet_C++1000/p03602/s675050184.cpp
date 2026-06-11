#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 300;
int N;
ll A[MAX_N+5][MAX_N+5], d[MAX_N+5][MAX_N+5];

void warshall_floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        }
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ll a; cin >> a;
            A[i][j] = d[i][j] = a;
        }
    }

    warshall_floyd();

    ll ans = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(A[i][j] != d[i][j]){
                cout << -1 << endl;
                return 0;
            }

            bool flg = true;
            for(int k=0;k<N;k++){
                if(i == k || j == k) continue;
                if(A[i][k]+A[k][j] == A[i][j]) flg = false;
            }

            if(flg) ans += A[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}