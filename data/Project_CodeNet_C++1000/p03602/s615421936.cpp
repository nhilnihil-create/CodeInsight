#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

long long n,a[305][305],t,v[305][305];

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            t+=a[i][j];
        }
    }
    t/=2;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(k==i || k==j) continue;
                if(a[i][k]+a[j][k]<a[i][j]){
                    cout << -1;
                    return 0;
                }
                if(a[i][k]+a[j][k]==a[i][j] && !v[i][j]){
                    t-=a[i][j];
                    v[i][j]=1;
                }
            }
        }
    }
    cout << t;
}
