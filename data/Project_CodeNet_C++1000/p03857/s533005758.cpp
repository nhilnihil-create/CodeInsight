#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int MAX_N = 2e5;
int N, K, L, parent[MAX_N], hight[MAX_N], road[MAX_N];

void init(int n){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        hight[i] = 0;
    }
}

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(hight[x]<hight[y]) parent[x] = y;
    else{
        parent[y] = x;
        if(hight[x] == hight[y]) hight[x]++;
    }
}

int main(){
    cin >> N >> K >> L;
    init(N);
    for(int i=0;i<K;i++){
        int p, q; cin >> p >> q;
        unite(p, q);
    }
    for(int i=1;i<=N;i++) road[i] = find(i);

    init(N);
    for(int i=0;i<L;i++){
        int p, q; cin >> p >> q;
        unite(p, q);
    }

    map<P, int> cnt;
    for(int i=1;i<=N;i++) cnt[P(road[i], find(i))]++;
    for(int i=1;i<=N;i++) cout << cnt[P(road[i], parent[i])] << ' ';
    cout << endl;
    
    return 0;
}
