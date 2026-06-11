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
    string s,ans="";
    cin>>s;

    rep(i,s.size()){
        if(s[i]=='0'){
            ans.push_back('0');
        }
        else if(s[i]=='1'){
            ans.push_back('1');
        }
        else if((s[i]=='B'&&ans.size()!=0)){
            ans.pop_back();
        }
    }

    cout<<ans<<endl;
}
