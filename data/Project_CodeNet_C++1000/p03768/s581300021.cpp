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

#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
using namespace std;

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

int n,m,q;
vi g[100010];
struct Q{int v,d,c;};
Q task[100010];
int col[100010];
int used[100010][12];
void func(int v,int d,int c){
    if(used[v][d])return;
    else{
        used[v][d] = 1;
        if(!col[v])col[v] = c;
    }
    if(d == 0)return;
    func(v,d-1,c);
    for(auto i : g[v]){
        func(i,d-1,c);
    }
    return;
}
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(20);
    cin >> n >> m;
    rep(i,m){
        int a,b;cin >> a >> b;
        a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    cin >> q;
    rep(i,q){
        int v,d,c;cin >> v >> d >> c;
        task[i] = {--v,d,c};
    }
    reverse(task,task + q);
    rep(i,q){
        func(task[i].v,task[i].d,task[i].c);
    }
    rep(i,n)cout << col[i] << '\n';
    return 0;
}
