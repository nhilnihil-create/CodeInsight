#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> c;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end());
    ll a=0,p=0;
    for(int i=N-1;i>0;--i) {
        int c = 1;
        for(int j=i-1;j>0;--j) {
            if(A[i] != A[j]) break;
            ++c;
        }
        if(c>=4) {
            cout << (ll)A[i]*A[i] << endl;
            return 0;
        }
        else if(c>=2) {
            a = A[i];
            p = i-c;
            break;
        }
    }
    if(!a) {
        cout << 0 << endl;
        return 0;
    }
    ll b=0;
    for(int i=p;i>0;--i) {
        if(A[i] == A[i-1]){
            b = A[i];
            break;
        }
    }
    if(!b) {
        cout << 0 << endl;
        return 0;
    }
    cout << a*b << endl;
    
}
