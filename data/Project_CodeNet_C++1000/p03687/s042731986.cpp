#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin>>s;
    int n=s.size();
    bool ok=true;
    rep(i,n-1)if(s[i]!=s[i+1]){
        ok=false;
    }
    if (ok){
        cout<<"0\n";
        return 0;
    }
    int ans=101010;
    rep(i,n){
        char c = s[i];
        string t = s;
        bool loop=true;
        int cnt=0;
        while(loop){
            loop=false;
            int m=t.size();
            rep(j,m-1)if(t[j]==c||t[j+1]==c){
                t[j]=c;
            }else{
                loop=true;
            }
            t.pop_back();
            cnt++;
        }
        chmin(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
