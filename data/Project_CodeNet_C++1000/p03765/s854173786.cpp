#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0, tmp1=0, tmp2=0;
string S, T;
vector<ll> A, B;

signed main(){
    cin >> S >> T >> N;
    A.resize(S.size()+1, 0);
    B.resize(T.size()+1, 0);
    for(int i=0;i<S.size();i++) {
        if(S[i]=='B') A[i+1]++;
    }
    for(int i=0;i<S.size();i++) {
        A[i+1] = A[i] + A[i+1];
        //cout << A[i+1] << " ";
    }
    //cout << endl;
    for(int i=0;i<T.size();i++) {
        if(T[i]=='B') B[i+1]++;
    }
    for(int i=0;i<T.size();i++) {
        B[i+1] = B[i] + B[i+1];
        //cout << B[i+1] << " ";
    }
    //cout << endl;
    for(int i=0;i<N;i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        tmp1 = b-a+1+A[b+1]-A[a];
        //cout << A[b+1] << " "  << A[a] << endl;
        tmp2 = d-c+1+B[d+1]-B[c];
        //cout << B[d+1] << " "  << B[c] << endl;
        //cout << tmp1 << " " << tmp2 << endl;
        tmp = abs(tmp1-tmp2);
        if(tmp%3==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}