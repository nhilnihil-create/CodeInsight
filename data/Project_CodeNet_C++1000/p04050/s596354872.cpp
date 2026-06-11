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

int arr[105];
vector<int> ans;

int main()
{
    IOS();
    int n,m,cnt,flag=0;
    cin >> n >> m,cnt=n&1;
    for(int i=0;i<m;++i)
        cin >> arr[i],cnt+=arr[i]&1;
    if(cnt>=3)
        return cout << "Impossible\n",0;
    if(n==1)
        return cout << "1\n1\n1\n",0;
    if(m==1)
        return cout << arr[0] << "\n2\n1 " << n-1 << "\n",0;
    for(int i=0;i<m;++i)
        if(arr[i]&1)
            if(!flag)
                flag=1,swap(arr[i],arr[0]);
            else
                swap(arr[i],arr[m-1]);
    ans.pb(arr[0]+1);
    for(int i=1;i+1<m;++i)
        ans.pb(arr[i]);
    if(arr[m-1]>1)
        ans.pb(arr[m-1]-1);
    for(int i=0;i<m;++i)
        cout << arr[i] << " \n"[i+1==m];
    cout << SZ(ans) << "\n";
    for(int i=0;i<SZ(ans);++i)
        cout << ans[i] << " \n"[i+1==SZ(ans)];
}