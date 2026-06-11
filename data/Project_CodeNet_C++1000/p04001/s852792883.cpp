#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl
int main(){
    string S; cin>>S;
    int N=S.size();
    ll ans=0;

    for(int bit=0; bit< (1<<(N-1)); bit++){
        ll tmp=0;
        for(int i=0; i<N-1; i++){
            tmp *= 10;
            tmp+= S[i]-'0';
            if(bit & (1 << i)){
                ans += tmp;
                tmp =0;
            }
        }
        tmp *= 10;
        tmp += S.back() - '0';
        ans += tmp;
    }
    cout<<ans<<endl;
}