#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    ll res=0;
    VVI a(n,vector<ll>(n)),dis(n,vector<ll>(n,INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> a[i][j];
            dis[i][j]=a[i][j];
            if(i==j) dis[i][j]=dis[j][i]=0;
            res+=a[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    res/=2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dis[i][j]<a[i][j]){
                cout<<-1<<endl;
                return 0;
            }
            bool flag=false;
            for(int k=0;k<n;k++){
                if(i==k || j==k) continue;
                if(dis[i][j]==dis[i][k]+dis[k][j]) flag=true;
            }
            if(flag) res-=dis[i][j];
        }
    }
    cout<<res<<endl;
}
