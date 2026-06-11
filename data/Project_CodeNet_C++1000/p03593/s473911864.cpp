#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);
int main(){
    int h,w;cin>>h>>w;
    vector<string>a(h);
    rep(i,h)cin>>a[i];
    map<char,int>st;
    map<int,int>me;
    rep(i,h)rep(j,w)st[a[i][j]]++;
    bool f[h][w];
    rep(i,h)rep(j,w)f[i][j]=true;
    rep(i,(h+1)/2)rep(j,(w+1)/2){
        int cnt=0;
        if(f[i][j]){
            f[i][j]=false;
            cnt++;
        }
        if(f[i][w-j-1]){
            f[i][w-j-1]=false;
            cnt++;
        }
        if(f[h-i-1][j]){
            f[h-i-1][j]=false;
            cnt++;
        }
        if(f[h-i-1][w-j-1]){
            f[h-i-1][w-j-1]=false;
            cnt++;
        }
        //cout<<cnt<<' '<<i<<' '<<j<<endl;
        me[cnt]++;
    }
    for(auto x:st){
        int w =x.second;
        while(w>=4){
            if(me[4]==0)break;
            if(w==0)break;
            w-=4;
            me[4]--;
        }
        while(w>=2){
            if(me[2]==0)break;
            if(w==0)break;
            w-=2;
            me[2]--;
        }
        if(w&&me[1]){
            me[1]--;
            w--;
        }
        if(w){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}