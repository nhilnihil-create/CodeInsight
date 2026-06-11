//52行目から編集
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}

template<class T> void debugger(vector<vector<T> >& a,int n = -1,int m = -1){
    if(n == -1 && m == -1)n = a.size(),m = a[0].size();
    rep(i,n){ rep(j,m){ cerr << setw(5) << (a[i][j] >= 9999 ? 9999 : a[i][j]); } cerr << endl; }
}
template<class T> void debugger(vector<T> & a,int n = -1){
    if(n == -1)n = a.size();
    rep(i,n){cerr << setw(5) << (a[i] >= 9999 ? 9999 : a[i]);} cerr << endl;
}
///////////////////////////////////////////////////////////

int n,m;
int a[1010],b[1010],c[1010];
int dist[110][110];

int main(void){
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j)dist[i][j] = 0;
            else dist[i][j] = 1e8;
        }
    }
    rep(i,m){
        cin  >> a[i] >> b[i] >> c[i];
        a[i]--,b[i]--;
        chmin(dist[a[i]][b[i]],c[i]);
        chmin(dist[b[i]][a[i]],c[i]);
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                chmin(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    int ans = m;
    for(int i = 0;i < m;i++){
        for(int s = 0;s < n;s++){
            //cerr << dist[s][b[i]] << ' ' << dist[s][a[i]] << ' ' << dist[a[i]][b[i]] << endl;
            if(dist[s][b[i]] == (dist[s][a[i]] + c[i])){
                ans--;
                break;
            }
        }
    }
    cout << ans << '\n';
}

/*
 *!!CHECK!! 
 * 制約をよく読め：まず最も愚直な解法を考えろ
 * intの掛け算をしてる場合：overflowは大丈夫？
 * 制約の下限・上限は大丈夫？
 * 木構造は一直線にした時TLEしない？
 * */
