#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piiii pair<pii,pii>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define logg2 0.30102999566398119521373889472449L
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e5+5;


vector<int> adj2[maxn+1];
int nex_node[maxn+1];
int red[maxn+1],ball[maxn+1];
int x,y;
void solve(){
    int n,m;cin>>n>>m;
    red[1]=1;ball[1]=1;
    for(int i=2;i<=n;i++) {red[i]=0;ball[i]=1;}
    while(m--){
        cin>>x>>y;
        if(red[x]==0){
            ball[x]--;
            ball[y]++;
        }
        else if(red[x]==1 && ball[x]==1){
            red[x]=ball[x]=0;
            red[y]=1;ball[y]++;
        }
        else{
            red[y]=1;ball[y]++;
            ball[x]--;
        }


    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(red[i]) cnt++;
    }
    cout<<cnt;
    return;
}
int main(){
    IO

    //TEST
    solve();
    return(0);
}
