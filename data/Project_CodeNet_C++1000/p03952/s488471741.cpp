#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N,x;
    cin >> N >> x;
    if (x==1||x==2*N-1){
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        if (N==2&&x==2){
            cout << 1 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
        }
        ll now=1;
        if (x!=2){
            rep2(i,1,2*N){
                if (i==N-1){
                    cout << x-1 << endl;
                    cout << x << endl;
                    cout << x+1 << endl;
                    cout << x-2 << endl;
                    if (now==x-2){
                        now+=4;
                    }
                    i+=3;
                }
                else if (now==x-2){
                    cout << now+4 << endl;
                    now+=5;
                }
                else {
                    cout << now << endl;
                    now++;
                }
            }
        }
        else if(N!=2){
            now=5;
            rep2(i,1,2*N){
                if (i==N-1){
                    cout << 3 << endl;
                    cout << 2 << endl;
                    cout << 1 << endl;
                    cout << 4 << endl;
                    i+=3;
                }
                else {
                    cout << now << endl;
                    now++;
                }
            }
        }
    }
}