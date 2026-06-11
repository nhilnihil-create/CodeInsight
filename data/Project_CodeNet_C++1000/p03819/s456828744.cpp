#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 300009;

struct Node{    
    int value;
    int lef;
    int rig;
};

Node T[6000000];
int root[N];
int cnt;

int build(int cl, int cr){
    int nd = cnt;
    T[nd] = {0,-1,-1};
    cnt ++ ;
    if(cl == cr)
        return nd;
    int mid = (cl + cr) / 2;
    T[nd].lef = build(cl,mid);
    T[nd].rig = build(mid+1,cr);
    return nd;
}

int update(int node, int cl, int cr, int pos){
    T[cnt] = T[node];
    node = cnt++;
    T[node].value ++ ;
    if(cl==cr)
        return node;
    int mid = (cl + cr) / 2;
    int f;
    if(mid >= pos){
        f = update(T[node].lef, cl, mid, pos);
        T[node].lef = f;
    }
    else{
        f = update(T[node].rig, mid + 1, cr, pos);
        T[node].rig = f;
    }
    return node;
}

int query(int node, int cl, int cr, int tl, int tr){
    if(cr < tl)
        return 0;
    if(cl > tr)
        return 0;
    if(cl >= tl && cr <= tr)
        return T[node].value;
    int mid = (cl + cr) / 2;
    return query(T[node].lef, cl, mid, tl, tr) + query(T[node].rig, mid + 1, cr, tl, tr);
}

vector<int> P[N];

int main(){
    int n, m;
    cin >> n >> m;
    int li, ri;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> li >> ri;
        P[li].push_back(ri);
    }
    root[0] = build(1, m);
    int fi;
    for(int i = 1; i <= m ; i ++ ){
        root[i] = root[i-1];
        for(auto x : P[i]){
            fi = update(root[i], 1, m, x);
            root[i] = fi;
        }
    }
    int L,R;
    int res;
    for(int i = 1; i <= m ; i ++ ){
        res = 0;
        for(int j = i ; j <= m ; j += i){
            L = j;
            R = min(m, L + i - 1);
            res += query(root[j], 1, m, L, R);
        }
        cout << res << "\n";
    }
    return 0;
}