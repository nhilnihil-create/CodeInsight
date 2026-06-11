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
///////////////////////////////////////////////////////////

ll dp[100010][3];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(20);
    
    rep(i,3)rep(j,100010)dp[i][j] = -LONG_MAX / 100;

    int n;cin >> n;
    vector<ll> a(n);
    vector<char> s(n);
    for(int i = 0;i < n;i++){
        if(i == 0){
            cin >> a[i];
            s[i] = '+';
        }else{
            cin >> s[i] >> a[i];
        }
    }

    dp[0][0] = a[0];
    for(int i = 1;i < n;i++){
        if(s[i] == '+'){
            chmax(dp[i][0],dp[i-1][0] + a[i]);
            chmax(dp[i][0],dp[i-1][1] - a[i]);

            chmax(dp[i][1],dp[i-1][1] - a[i]);
            chmax(dp[i][1],dp[i-1][2] + a[i]);

            chmax(dp[i][2],dp[i-1][2] + a[i]);
        }else{
            chmax(dp[i][1],dp[i-1][0] - a[i]);
            chmax(dp[i][0],dp[i-1][0] - a[i]);

            chmax(dp[i][2],dp[i-1][1] + a[i]);
            chmax(dp[i][1],dp[i-1][1] + a[i]);

            chmax(dp[i][2],dp[i-1][2] + a[i]);
        }
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << '\n';
    //rep(i,3){
    //    rep(j,n){
    //        cout << setw(4) << (dp[j][i] < -1000 ? "-INF" : to_string(dp[j][i]));
    //    }
    //    cout << '\n';
    //}
    return 0;
}
/*
 *!!CHECK!! 
 * 制約をよく読め：まず最も愚直な解法を考えろ
 * intの掛け算をしてる場合：overflowは大丈夫？
 * 制約の下限・上限は大丈夫？
 * 木構造は一直線にした時TLEしない？
 * */
