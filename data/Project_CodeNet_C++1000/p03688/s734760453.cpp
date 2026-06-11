#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    int m=N,M=0;
    rep(i,N){
        cin >> a[i];
        m=min(m,a[i]);
        M=max(M,a[i]);
    }
    if (M-m>1){
        cout << "No" << endl;
    }
    else if (M==m){
        if (N>=M*2||M==N-1){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        int count=0;
        rep(i,N){
            if (a[i]==m){
                count++;
            }
        }
        if (M<=count){
            cout << "No" << endl;
        }
        else if (M*2-count<=N){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}