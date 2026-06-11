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
ll i,j,k;
// #define max 105

int main(){
    fio();
    ll a,b;
    cin>>a>>b;
    cout<<(a+b)%24;

}