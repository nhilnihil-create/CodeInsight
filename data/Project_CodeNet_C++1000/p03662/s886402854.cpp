#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i , j , n) for(long long i = j ; i <= n ; i++)
const ll N = 123456;
vector < int > a[N];

int fe[N];
int snu[N];

void dfs(int s, bool flag) {
    for(int i : a[s]) {
        if(flag == true && fe[i] != 0) continue;
        if(flag == false && snu[i] != 0) continue;
        if(flag == true) {
            fe[i] = fe[s] + 1;
        }
        else {
            snu[i] = snu[s] + 1;
        }
        dfs(i , flag);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    rep(i , 1 , n - 1) {
        int x , y;
        cin >> x >> y;

        a[x].push_back(y);
        a[y].push_back(x);
    }

    fe[1] = 1;
    snu[n] = 1;

    dfs(1 , true);
    dfs(n , false);

    int f = 0;
    int s = 0;

    rep(i , 1 , n) {
        if(fe[i] <= snu[i]) {
            f++;
        }
        else s++;
    }

    if(f > s) {
        cout << "Fennec" << endl;
    }
    else cout << "Snuke" << endl;
    return 0;
}
