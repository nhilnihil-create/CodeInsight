#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A, D;
string S;

signed main(){
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        if(S[i]=='o') A.push_back(0);
        else A.push_back(1);
    }
    D.resize(N, -1);
    D[N-1] = 0;
    D[0] = 0;
    D[1] = A[0]^D[0]^D[N-1];
    for(int i=1;i<N-2;i++) {        
        D[i+1] = A[i]^D[i]^D[i-1];
    }
    if(D[N-1]==A[N-2]^D[N-2]^D[N-3]&&D[0]==A[N-1]^D[N-1]^D[N-2]) ans++;
    if(ans>0) {
        for(int i=0;i<N;i++) {
            if(D[i]==0) cout << "S";
            else cout << "W";
        }
        return 0;
    }
    D.resize(N, -1);
    D[N-1] = 0;
    D[0] = 1;
    D[1] = A[0]^D[0]^D[N-1];
    for(int i=1;i<N-2;i++) {        
        D[i+1] = A[i]^D[i]^D[i-1];
    }
    if(D[N-1]==A[N-2]^D[N-2]^D[N-3]&&D[0]==A[N-1]^D[N-1]^D[N-2]) ans++;
    if(ans>0) {
        for(int i=0;i<N;i++) {
            if(D[i]==0) cout << "S";
            else cout << "W";
        }
        return 0;
    }
    D.resize(N, -1);
    D[N-1] = 1;
    D[0] = 0;
    D[1] = A[0]^D[0]^D[N-1];
    for(int i=1;i<N-2;i++) {        
        D[i+1] = A[i]^D[i]^D[i-1];
    }
    if(D[N-1]==A[N-2]^D[N-2]^D[N-3]&&D[0]==A[N-1]^D[N-1]^D[N-2]) ans++;
    if(ans>0) {
        for(int i=0;i<N;i++) {
            if(D[i]==0) cout << "S";
            else cout << "W";
        }
        return 0;
    }
    D.resize(N, -1);
    D[N-1] = 1;
    D[0] = 1;
    D[1] = A[0]^D[0]^D[N-1];
    for(int i=1;i<N-2;i++) {        
        D[i+1] = A[i]^D[i]^D[i-1];
    }
    if(D[N-1]==A[N-2]^D[N-2]^D[N-3]&&D[0]==A[N-1]^D[N-1]^D[N-2]) ans++;
    if(ans>0) {
        for(int i=0;i<N;i++) {
            if(D[i]==0) cout << "S";
            else cout << "W";
        }
        return 0;
    }
    else cout << -1 << endl;
    return 0;
}