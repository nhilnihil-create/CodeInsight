#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;
 
int main()
{
    int N;   cin >> N;
    ll mod2 = 1000000007;
    ll ans = 1;
    vector<ll> T(N), A(N), e(N,0), maxt(N);
    for(int i=0; i<N; i++)  cin >> T[i];
    for(int i=0; i<N; i++)  cin >> A[i];
    if(T[N-1] != A[0])  ans = 0;
    e[0] = T[0];
    for(int i=1; i<N; i++){
        if(T[i] > T[i-1]){
            e[i] = T[i];
            maxt[i] = T[i];
        }else   maxt[i] = maxt[i-1];
    }
    if(e[N-1] > 0 && e[N-1] != A[N-1]){
        ans = 0;
    }else{
        e[N-1] = A[N-1];
        for(int i=N-2; i>=0; i--){
            if(A[i] > A[i+1]){
                if(A[i] > maxt[i]){
                    ans = 0;
                }else{
                    e[i] = A[i];
                }
            }
        }
    }
    for(int i=0; i<N; i++){
        if(e[i] == 0){
            ans *= min(A[i],T[i]);
            ans %= mod2;
        }
    }
    cout << ans;
}