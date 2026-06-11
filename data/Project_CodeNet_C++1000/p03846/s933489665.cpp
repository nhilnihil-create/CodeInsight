#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    cin >> N;
    bool even = false;
    if(N % 2 == 0){
        even = true;
    }
    vector<ll> A(N),memo(N,0);
    rep(i,N){
        cin >> A[i];
        if(even){
            if(A[i] % 2 == 0){
                cout << 0 << endl;
                return 0;
            }
        }else{
            if(A[i] % 2 == 1){
                cout << 0 << endl;
                return 0;
            }
        }
        memo[A[i]]++;
    }
    if(N == 1 && A[0] == 0){
        cout << 1 << endl;
        return 0;
    }
    if(even){
        if(memo[0] != 0){
            cout << 0 << endl;
            return 0;
        }
    }else{
        if(memo[0] != 1){
            cout << 0 << endl;
            return 0;
        }
    }
    //cout << "AAA"<<endl;
    if(even){
        rep(i,ll(N/2) + 1){
            if(memo[i+1] != 2){
                cout << 0 << endl;
                return 0;        
            }
        i++;
        }
    }else{
        rep(i,ll(N/2) + 1){
            if(memo[i+2] != 2){
                cout << 0 << endl;
                return 0;        
            }
        i++;
        }
    }
    //cout << "BBB"<<endl;


    ll tot = 1;
    rep(i, N/2){
        tot *= 2;
        tot %= mo;
    }
    cout << tot << endl;
}
