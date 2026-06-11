#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, X, ans=1, tmp=0;
vector<ll> A;

signed main(){
    cin >> N >> X;
    A.resize(2*N-1);
    if(X==1||X==2*N-1) {
        cout << "No" << endl;
        return 0;
    }
    while(2*N-1-X>=tmp&&X-1>=tmp) {
        A[N-1-tmp] = X+ans*tmp;
        A[N-1+tmp] = X-ans*tmp;
        tmp++;
        ans *= (-1);
    }
    ll now = tmp;
    if(X-1<tmp) {
        while(tmp<=N-1) {
            A[N-1-tmp] = X+now;
            now++;
            A[N-1+tmp] = X+now;
            now++;
            tmp++;
        }
    }
    else {
        while(tmp<=N-1) {
            A[N-1-tmp] = X-now;
            now++;
            A[N-1+tmp] = X-now;
            now++;
            tmp++;
        }
    }
    cout << "Yes" << endl;
    for(int i=0;i<2*N-1;i++) {
        cout << A[i] << endl;
    }
    return 0;
}