#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    int k,s;
    cin>>k>>s;

    int cnt=0;

    rep2(i,0,k){
        rep2(j,0,k){
            if(s-i-j<=k&&s-i-j>=0){
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
}
