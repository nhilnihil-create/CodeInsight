
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define loop(i,a,n) for(int i = a; i < (n); i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

#define max_n 100005

vector<vi> g(max_n);
int a[max_n];
int n;
bool ans = true;
ll dfs(int now, int p){
    if(g[now].size() == 1){ //葉
        return a[now];
    }

    ll sum = 0;
    ll max_ci = 0;
    rep(i,g[now].size())if(g[now][i] != p){
        ll t = dfs(g[now][i], now);
        sum += t;
        max_ci = max(max_ci, t);
    }
    ll t = 2 * a[now] - sum;
    ll l = (sum - t) / 2;



    if(t < 0 || l < 0){
        ans = false;
    }

    if(p == -1 && t){
        ans = false;
    }

    if(2 * max_ci >= sum){
        if(l > sum - max_ci)
            ans = false;
    }else{
        if(2 * l > sum)
            ans = false;
    }
    
    return t;
}

int main(void) {
    cin>>n;
    rep(i,n) cin >> a[i];

    rep(i,n-1){
        int x,y;
        cin >> x >> y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if(n == 2){
        if(a[0] == a[1]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return 0;
    }
    int root;
    rep(i,n)if(g[i].size() >= 2){
        root = i;
        break;
    }

    dfs(root, -1);

    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
