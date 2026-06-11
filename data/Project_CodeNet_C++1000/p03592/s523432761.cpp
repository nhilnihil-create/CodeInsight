#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const long long inf = 1e9+7;
const long long mod = 1e9+7;

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    rep2(i,0,n){
        rep2(j,0,m){
            if((n-i)*j+(m-j)*i==k){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;
}
