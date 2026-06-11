#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std; 
int n, m;
const int maxn = 4e5 + 5;

int a[maxn];
typedef long long LL;
LL c[2][maxn];

void add(int id, int x, int d){
    for(int i = x;i < maxn;i += i & -i){
        c[id][i] += d;
    }
}

LL sum(int id, int x){
    LL res = 0;
    for(int i = x;i > 0;i -= i & -i){
        res += c[id][i];
    }
    return res;
}

void add1(int id, int l, int r, int v){
    add(id, l, v);
    add(id, r + 1, -v);
}

LL query(int x){
    return sum(0, x) * x + sum(1, x);
}

int main(){
    //freopen("in/mx1.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i < n;i++){
        if(a[i + 1] > a[i]){
            add1(1, 1, m, a[i + 1] - a[i]);
            add1(1, a[i] + 1, a[i + 1], a[i] + 1);
            add1(0, a[i] + 1, a[i + 1], -1);
        }else{
            add1(1, 1, m, a[i + 1] + m - a[i]);
            add1(1, a[i] + 1, m, a[i] + 1);
            add1(1, 1, a[i + 1], a[i] + 1 - m);
            add1(0, a[i] + 1, m, -1);
            add1(0, 1, a[i + 1], -1);
        }
    }
    for(int i = 1;i <= 2 * m;i++){
        //cout << i << " " << sum(0, i) << " " << sum(1, i) << endl;
    }
    LL ans = query(1);
    for(int i = 2;i <= m;i++){
        //cout << ans << endl;
        ans = min(ans, query(i));
    }
    cout << ans << endl;
    return 0;
}
