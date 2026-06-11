#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int dist[105][105];
int main(){
    int n,m;cin >> n >> m;
    vector<int> a(m),b(m),c(m);
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=INF;
            if(i==j) dist[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        dist[a[i]][b[i]]=min(dist[a[i]][b[i]],c[i]);
        dist[b[i]][a[i]]=min(dist[b[i]][a[i]],c[i]);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int ans=0;
    for (int i = 0; i < m; i++)
    {
        if(dist[a[i]][b[i]]<c[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}