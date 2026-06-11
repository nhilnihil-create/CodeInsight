#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const long long INF = 1e15;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
typedef pair<int,int> pii;
int main(){
    int n;
    cin >> n;
    long long distance[n+1][n+1];
    long long ans = 0;
    rep(i,n+1){
        rep(j,n+1){
            if(i==j) distance[i][j]=0;
            else distance[i][j] = INF;
        }
    }
    long long a[n+1][n+1];
    rep(i,n){
        rep(j,n){
            cin >> a[i+1][j+1];
            distance[i+1][j+1] = a[i+1][j+1];
            ans+=a[i+1][j+1];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                distance[j][k] = min(distance[j][k],distance[j][i]+distance[i][k]);
            }
        }
    }
    rep(i,n){
        rep(j,n){
            if(distance[i+1][j+1]<a[i+1][j+1]){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    ans/=2;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                if(k!=i && k!=j){
                    if((distance[i][k]+distance[k][j])==a[i][j]){
                        ans-=a[i][j];
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}