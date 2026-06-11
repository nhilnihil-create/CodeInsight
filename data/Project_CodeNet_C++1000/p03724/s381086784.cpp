#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, m;
set <pair <int, int> > s;

void add(int a, int b){
    if(s.count(make_pair(a, b))){
        s.erase(make_pair(a, b));
    }
    else s.insert(make_pair(a, b));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        if(y < x) swap(x, y);
        if(x == 1) add(x, y);
        else{
            add(1, x);
            add(1, y);
        }
    }
    if(s.size() == 0) cout << "YES\n";
    else cout << "NO\n";
}
