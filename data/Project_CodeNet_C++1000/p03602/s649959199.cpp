#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

ll d[310][310];
bool del[310][310];
int n;
ll sum;

bool warshall(){
    rep(k,n){
        rep(i,n){
            rep(j,i){
                if(chmin(d[i][j],d[i][k]+d[k][j]))return false;
                if(d[i][j]==d[i][k]+d[k][j] && i!=k && j!=k && !del[i][j]){
                  	sum-=d[i][j];
                  	del[i][j]=true;
                }
            }
        }
    }
  	return true;
}

int main() {
    cin >> n;
    sum=0;
    rep(i,n){
        rep(j,n){
            cin >> d[i][j];
            sum+=d[i][j];
        }
    }
  	sum/=2;
    rep(i,n){
        rep(j,n){
            if(d[i][j]!=d[j][i]){
                cout << -1;
                return 0;
            }
        }
    }
  	rep(i,n)rep(j,n)del[i][j]=false;
    if(warshall()){
        cout << sum;
    }
    else cout << -1;
    


}

/*



 */

