#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s; cin>>s;
    ll cnt=0;
    rep(i,0,s.size()){
        if(s[i]=='A'){
            for(ll j=s.size()-1; j>=i; j--){
                cnt = j-i+1;
                if(s[j]=='Z')break;
            }
            if(cnt!=0)break;
        }
    }
    cout << cnt << endl;
    return 0;
}