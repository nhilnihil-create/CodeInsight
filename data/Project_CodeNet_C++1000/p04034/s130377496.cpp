#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

int ball[100005],type[100005];

int main()
{
    IOS();
    int n,m,a,b,p=0,nw=1;
    cin >> n >> m;
    for(int i=1;i<=n;++i)
        ball[i]=1;
    while(m--)
    {
        cin >> a >> b;
        if(!p)
            if(a!=nw&&b!=nw)
                --ball[a],++ball[b];
            else if(b==nw)
                p=1,--ball[a],++ball[b],type[b]=1;
            else if(ball[b]==0)
                --ball[a],++ball[b],nw=b;
            else
                p=1,--ball[a],++ball[b],type[b]=1;
        else if(!type[a])
            --ball[a],++ball[b];
        else if(ball[a]==1)
            --ball[a],++ball[b],type[a]=0,type[b]=1;
        else 
            --ball[a],++ball[b],type[b]=1;
    }
    cout << count(type+1,type+n+1,1) << "\n";
}