#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
using tpl = tuple<ll, ll, ll>;
typedef pair<ll,ll> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

ll N;
ll A[310][310];

int main(){

    cin >> N;

    ll sum = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            cin >> A[i][j];
            sum += A[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            bool flag = false;
            for(int k = 0; k < N; k++){
                if(A[i][k] + A[k][j] <= A[i][j]){
                    if(A[i][k] + A[k][j] != A[i][j]){
                        cout << -1 << endl;
                        return 0;
                    }
                    if(k==j||k==i){
                    }
                    else{
                        flag = true;
                    }
                }
            }
            if(flag) {
                sum -= A[i][j];
            }
        }
    }

    cout << sum / 2 << endl;
    
    return 0;
}
