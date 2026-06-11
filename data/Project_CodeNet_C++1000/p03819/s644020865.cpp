#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FRE freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define SET(A,VAL) memset(A, VAL, sizeof(A))
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
const int MAX = 1e6+8;
const int sz = 1e5+5;
void f_io(){
    IOS;
    // #ifndef ONLINE_JUDGE
    // FRE
    // #endif
}

std::vector<pair<int,pii>> seg;
vi BIT;
void update(int at,int by){
    while (at < BIT.size()){
        BIT[at] += by;
        at += (at&(-at));
    }

}
void updateR(int l,int r, int val){
    update(l,val);
    update(r+1,-val);
}
int query(int at){
    int ret = 0;
    while (at > 0){
        ret += BIT[at];
        at -= (at&(-at));
    }
    return ret;
}
int n,m;
int32_t main(){
    f_io();
    int t = 1;
    //cin>>t;
    while(t--){
        cin >> n >> m;
        BIT.resize(m+1,0);
        rep(i,0,n){
            int a,b; cin >> a >> b;
            seg.pb({b-a+1,{a,b}});
        }
        sort(seg.begin(), seg.end());
        int idx = 0,base = n;
        rep(d,1,m+1){
            for(; idx < n; idx++){
                auto s = seg[idx];
                if(s.ff < d){
                    base--;
                    updateR(s.ss.ff,s.ss.ss, 1);
                }
                else break;
            }
            int fans = 0;
            for(int k = d;k < m+1; k += d){
                fans += query(k);
            }
            cout << fans + base << endl;
        }
    }
}