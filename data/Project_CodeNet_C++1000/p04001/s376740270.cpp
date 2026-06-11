#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main() {
    string S;
    cin>>S;
    ll ans = 0,shiki,now;

    for(int bit=0;bit<(1<<S.size()-1);bit++){
        now=(S[0]-'0');
        shiki=0;
        rep(i,S.size()-1){
            if(bit&(1<<i)){
                shiki+=now;
                now=(S[i+1]-'0');
            }else{
                now=now*10+(S[i+1]-'0');
            }
        }
        shiki+=now;
        ans+=shiki;
    }
    cout << ans << endl;
}