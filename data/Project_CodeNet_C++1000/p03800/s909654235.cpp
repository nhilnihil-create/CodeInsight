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
}
int32_t main(){
    f_io();
    int t = 1;
    //cin>>t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        bool ret[n+1] = {0};
        for(auto k : {0,1}){
            for(auto j : {0,1}){
                ret[0] = k, ret[1] = j;
                rep(i,1,n){
                    if(s[i] == 'o') ret[i+1] = ret[i-1];
                    else ret[i+1] = !ret[i-1];
                    if(!ret[i]) ret[i+1] = !ret[i+1];
                }
                bool ans0;
                if(s[0] == 'o') ans0 = ret[1];
                else ans0 = !ret[1];
                if(!ret[0]) ans0 = !ans0;
                if(ans0 != ret[n-1] || ret[0] != ret[n]) continue;
                rep(i,0,n){
                    if(ret[i]) cout << "S";
                    else cout << "W";
                }
                return 0;
            }
        }
        cout << "-1" << endl;

    }
}