#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#include<complex>
#include<map>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<double,double>pdd;
typedef pair<ll,ll>pll;
int main(){
    int h,w; cin>>h>>w;
    vector<vector<string>>v(h,vector<string>(w));
    char p;
    rep(i,h)rep(j,w){rep(slsl,5){cin>>p; v[i][j].push_back(p);}}
    string snuke="snuke";
    pii ans;
    rep(i,h)rep(j,w)if(v[i][j]==snuke)ans=pii(i,j);
    char hoge[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout<<hoge[ans.second]<<ans.first+1<<endl;
    
}