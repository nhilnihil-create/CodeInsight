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

int arr[100005];
deque<pii> dq;// 0: 0101... 1:11....

int main()
{
    IOS();
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> arr[i];
    sort(arr,arr+n),dq.pb(pii(0,arr[0]));
    for(int i=1;i<n;++i)
    {
        if(arr[i]==arr[i-1])
            dq.pb(pii(dq.back().X^1,1));
        else
            dq.pb(pii(((arr[i]-arr[i-1])|~dq.back().X)&1,1)),dq.pb(pii(0,arr[i]-arr[i-1]));
        if(dq[0].Y>1)
            --dq[0].Y;
        else
            dq.pop_front();
    }
    if(~dq[0].X&dq[0].Y&1)
        cout << "Second\n";
    else
        cout << "First\n";
}