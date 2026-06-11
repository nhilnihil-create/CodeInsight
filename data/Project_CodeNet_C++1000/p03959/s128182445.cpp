#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int N;
    cin >> N;
    int T[N], A[N];
    for(int i = 0; i < N; i++)  cin >> T[i];
    for(int i = 0; i < N; i++)  cin >> A[i];
    
    int confirmT[N], confirmA[N];
    ll ans = 1;
    for(int i = 0; i < N; i++){
        confirmT[i] = -1;
        confirmA[i] = -1;
    }
    
    
    confirmT[0] = T[0], confirmA[N - 1] = A[N - 1];
    for(int i = 1; i < N; i++){
        if((T[i - 1] != T[i]) || T[i] == 1) confirmT[i] = T[i];
        if((A[N - 1 - i] != A[N - i]) || A[N - i] == 1) confirmA[N - 1 - i] = A[N - 1 - i];
    }
    
    for(int i = 0; i < N; i++)
        if(confirmT[i] != -1 && confirmA[i] == -1){
            if(confirmT[i] > A[i]){
                cout << 0 << "\n";
                return 0;
            }
        }
        else if(confirmT[i] == -1 && confirmA[i] != -1){
            if(T[i] < confirmA[i]){
                cout << 0 << "\n";
                return 0;
            }
            confirmT[i] = confirmA[i];
        }
        else if(confirmT[i] != confirmA[i]){
            cout << 0 << "\n";
            return 0;
        }

    for(int i = 1; i < N; i++){
        if(confirmT[i] == -1){
            ans *= ((ll)min(T[i], A[i]) % mod);
            ans %= mod;
        }
    }

    cout << ans << "\n";
    return 0;
}