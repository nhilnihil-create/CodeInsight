/**
*    author:  yuya1234
*    created: 24.06.2020 16:55:05
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin>>s;

    bool flg;
    int ans = 0;

    FOR(i,97,97+25)
    {
        REP(j,s.size())
        {
            flg=false;
            if(s[j]==(char)i)
            {
                flg=true;
                break;
            }
        }
        if(!flg)
        {
            ans=i;
            break;
        }
    }

    if(ans==0)cout<<"None"<<endl;
    else cout<<(char)ans<<endl;

    return 0;
}