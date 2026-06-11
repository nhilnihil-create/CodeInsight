#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)
using Graph = vector<vector<int>>;
using pint = pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    int n,m,k;cin>>n>>m>>k;
    rep(i,n+1){
        rep(j,m+1){
            int a=i*(m-j)+j*(n-i);
            if(a==k){
                cout<<"Yes"<<"\n";
                return 0;
            }
        }
    }
    cout<<"No"<<"\n";
}