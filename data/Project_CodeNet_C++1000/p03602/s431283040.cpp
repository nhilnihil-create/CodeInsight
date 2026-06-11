#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <iomanip>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

const ll INF = 1LL<<60;
const ll MOD = 1000000007;

//cout << fixed << setprecision(10);

const ll N_MAX = 300;
vector<vector<ll>> A(N_MAX,vector<ll>(N_MAX));
ll N;

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            cin >> A[i][j];
        }
    }
    vector<Pll> Ps;
    vector<vector<ll>> B(N,vector<ll>(N,INF));
    for(int i=0;i<N;i++) B[i][i]=0;
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==k || j==k) continue;
                B[i][j] = min(B[i][j],A[i][k]+A[k][j]);
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(B[i][j]<A[i][j]){
                cout << -1 << endl;
                return 0;
            }
            else if(B[i][j]>A[i][j]) Ps.push_back(Pll(i,j));
        }
    }

    ll ans = 0;
    for(auto e : Ps){
        ans += A[e.first][e.second];
    }
    cout << ans/2 << endl;


    return 0;
}