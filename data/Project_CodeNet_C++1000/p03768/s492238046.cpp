#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int n, m;
vector<int> pathes[100200];
int q;
int a[100200], b[100200], v[100200], d[100200], c[100200];
int colors[100200];
int painted[100020];

void paint(int from, int distance, int color){
    if(distance <= painted[from]){
        return;
    }
    painted[from] = distance;
    if(colors[from] == 0){
        colors[from] = color;
    }
    if(distance == 0){
        return;
    }
    for(int i = 0; i < pathes[from].size(); i++){
        paint(pathes[from][i], distance - 1, color);
    }
    return;
}
int main() {
    //cout.precision(10);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i] >> b[i];
        pathes[a[i]].push_back(b[i]);
        pathes[b[i]].push_back(a[i]);
    }
    for(int i = 1; i <= n; i++){
        colors[i] = 0;
        painted[i] = -1;
    }
    cin >> q;
    for(int i = q; i >= 1; i--){
        cin >> v[i] >> d[i] >> c[i];
    }
    for(int i = 1; i <= q; i++){
        paint(v[i],  d[i], c[i]);
    }
    for(int i = 1; i <= n; i++){
        cout << colors[i] << endl;
    }
    return 0;
}
