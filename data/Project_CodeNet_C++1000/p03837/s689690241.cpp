#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
#define fio() cin.tie(0); ios::sync_with_stdio(false);
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define all(c) c.begin(),c.end()
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
#define pu push
#define pb push_back
vi dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
const ll MOD = 1000000007;
const int inf = 1000000001;
const ll INF = 1e16;
#define max 105

int main(){
    fio();
    ll ver,edge;
    cin>>ver>>edge;
    ll i,j,k,v1,v2,weight;
    int adjmat[max][max];
    int cost[max][max]; //defind to store shortest distance from any node to any node
    vii l(edge,vi(3));


    rep(i,105)
        rep(j,105){
            adjmat[i][j] = inf;
            if(i==j)
                adjmat[i][j] = 0;
        }
    rep(i,edge){
        cin>>v1>>v2>>weight;
        adjmat[v1][v2] = weight;
        adjmat[v2][v1] = weight;
        l[i][0] = v1;
        l[i][1] = v2;
        l[i][2] = weight;
    }
    rep1(i,ver)
        rep1(j,ver)
            cost[i][j] = adjmat[i][j]; 
    //floydWarshal algorithm
    rep1(k,ver){
        rep1(i,ver){
            rep1(j,ver){
                if(cost[i][k]+cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k]+cost[k][j];
            }
        }
    }
    ll ans=0;
    rep(i,edge){
        bool flag = false;
        rep1(j,ver){
            rep1(k,ver){
               if(cost[j][k] == cost[j][ l[i][0] ] + cost[ l[i][1] ][k] + l[i][2]  )
                    flag = true; 
            }
        }
        if(!flag)
            ans++;
    }
    cout<<ans;
    // rep1(i,ver){
    //     rep1(j,ver){
    //         cout<<cost[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // rep1(i,ver){
    //     rep1(j,ver){
    //         cout<<i<<" "<<j<<" "<<adjmat[i][j]<<endl;
    //     }
    // }


}
    //adj_list
    // vector< vector< pair<int, int> > > adjlist(ver + 1);
    // rep(i,edge){
    //     cin>>v1>>v2>>weight;
    //     adjlist[v1].pb( make_pair(v2,weight) );
    // }
    // rep(i,adjlist.size()){
    //     rep(j,adjlist[i].size()){
    //         cout<<i<<" "<<adjlist[i][j].first<<" "<<adjlist[i][j].second<<endl;
    //     }
    // }
