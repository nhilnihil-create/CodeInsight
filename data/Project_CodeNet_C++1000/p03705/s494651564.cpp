#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    if (N == 1){
        if (A == B) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else if (N == 2){
        if (A <= B) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else{
        if (A > B){
            cout << 0 << endl;
        }
        else{
            ll minsum = B + (N - 1) * A;
            ll maxsum = A + (N - 1) * B;
            cout << maxsum - minsum + 1 << endl;
        }
    }
}