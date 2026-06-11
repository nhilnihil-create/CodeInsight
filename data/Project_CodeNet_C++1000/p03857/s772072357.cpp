#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

struct dsu{
    vector <int> p;
    void resize(int n){
        p.resize(n + 1);
        for(int i = 1 ; i <= n ; i++){
            p[i] = i;
        }
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        p[x] = y;
    }
};

int n, k, l;
dsu a, b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> l;
    a.resize(n);
    b.resize(n);
    for(int i = 0 ; i < k ; i++){
        int x, y;
        cin >> x >> y;
        a.merge(x, y);
    }
    for(int i = 0 ; i < l ; i++){
        int x, y;
        cin >> x >> y;
        b.merge(x, y);
    }
    map <pair <int, int>, int> cnt;
    for(int i = 1 ; i <= n ; i++){
        cnt[make_pair(a.find(i), b.find(i))]++;
    }
    for(int i = 1 ; i <= n ; i++){
        cout << cnt[make_pair(a.find(i), b.find(i))] << " ";
    }
    cout << endl;
}
