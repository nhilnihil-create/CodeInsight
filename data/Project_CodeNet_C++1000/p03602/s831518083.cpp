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
    vector<pair<long long,pii>> data;
    long long tem;
    rep(i,n){
        rep(j,n){
            cin >> tem;
            if(j>i) data.push_back(make_pair(tem,make_pair(i+1,j+1)));
        }
    }
    sort(data.begin(),data.end());
    long long distance[n+1][n+1];
    rep(i,n+1){
        rep(j,n+1){
            distance[i][j]=INF;
        }
    }
    rep(i,n+1){
        distance[i][i] = 0;
    }
    int a,b;
    long long c;
    long long ans = 0;
    rep(i,data.size()){
        a = data[i].second.first;
        b = data[i].second.second;
        c = data[i].first;
        if(c>distance[a][b]){
            cout << "-1" << endl;
            //cout << "a: " << a << " b: " << b << " dist: " << distance[a][b] << " cost: "  << c << endl;
            return 0;
        }
        if(distance[a][b] != c){
            distance[a][b] = c;
            distance[b][a] = c;
            for(int j = 1;j<=n;j++){
                for(int k = 1;k<=n;k++){
                    distance[j][k] = min(distance[j][k],distance[j][a]+distance[a][k]);
                }
            }
            for(int j = 1;j<=n;j++){
                for(int k = 1;k<=n;k++){
                    distance[j][k] = min(distance[j][k],distance[j][b]+distance[b][k]);
                }
            }            
            ans+=c;
        }
        //cout << "dist: " << distance[1][4] << endl;
    }
    cout << ans << endl;
}
