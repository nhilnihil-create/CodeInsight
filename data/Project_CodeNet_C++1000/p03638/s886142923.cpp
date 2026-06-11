#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int h,w,n;cin>>h>>w>>n;
    vin a(n);rep(i,n)cin>>a[i];
    vvin ans(h,vin(w));
    int r=0;int c=0;
    rep(i,n){
        while(a[i]){
            ans[r][c]=i+1;
            if(r%2==0){
                if(c<w-1)c++;
                else r++;
            }
            else{
                if(0<c)c--;
                else r++;
            }
            a[i]--;
        }
    }
    rep(i,h){
        rep(j,w-1)cout<<ans[i][j]<<" ";
        cout<<ans[i][w-1]<<endl;
    }
}