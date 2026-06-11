#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, m;
    cin >> n >> m;;
    set<int> counter;
    counter.insert(0);
    vector<int> num(n, 1);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        num[x]--;
        num[y]++;
        if(counter.count(x)){
            counter.insert(y);
            if(num[x] <= 0){
                counter.erase(x);
            }
        }
    }
    cout << counter.size() << endl;
}