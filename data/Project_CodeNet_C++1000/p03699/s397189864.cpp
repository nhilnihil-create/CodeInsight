#include <bits/stdc++.h>

using namespace std;
using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e9+7;
const ll mod = 1e9+7;

int main(){
    int n,sum=0;
    cin>>n;

    vector<int>s(n);
    rep(i,n){
        cin>>s[i];
        sum+=s[i];
    }

    if(sum%10!=0){
        cout<<sum<<endl;
        return 0;
    }

    sort(s.begin(),s.end());

    rep(i,n){
        if(s[i]%10!=0){
            cout<<sum-s[i]<<endl;
            return 0;
        }
    }
    cout<<0<<endl;

}
