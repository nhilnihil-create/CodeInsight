#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<double, double> Pdd;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;

const ll mod = 1e9+7;
const int INF = 2e9;
const double epsilon = 1e-7;
const double PI = 3.1415926535;

ll mi(ll x, ll y){
    if(x<y)return x;
    return y;
}
int a[100000];
vector <int> t[100000];
int di[100000];
priority_queue <P> que;
void res(int now, int dist){
    if(di[now] != -1)return;
    di[now] = dist; que.push(P(dist, now));
    for(int i = 0;i < t[now].size();i++)res(t[now][i], dist+1);
    return;
}
void cl(int now){
    if(di[now] == 0)return;
    di[now] = 0;
    for(int i = 0;i < t[now].size();i++)cl(t[now][i]);
}
int main(void){
    int n, k; cin >> n >> k; ll ans = 0;
    for(int i = 0;i < n;i++){
        int aa; cin >> aa; aa--; t[aa].push_back(i);
        a[i] = aa;
    }
    fill(di, di+n, -1);
    res(0, 0);
    //for(int i = 0;i < n;i++)cout << di[i] << endl;
    if(k == 1){
        for(int i = 0;i < n;i++)if(a[i] != 0)ans++;
        cout << ans << endl;
        return 0;
    }
    if(a[0] != 0)ans++;
    while(!que.empty()){
        P p = que.top(); que.pop();
        //cout << p.first << " " << p.second << " " <<  ans << endl;
        if(di[p.second] > k){
            ans++;
            int w = p.second;
            for(int i = 0;i < k-1;i++)w = a[w];
            cl(w);
        }
    }
    cout << ans << endl;
	return 0;
}