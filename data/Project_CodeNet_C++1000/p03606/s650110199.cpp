#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
vector<int> l;
vector<int> r;
int ans = 0;

void input(){
    cin >> n;
    l.resize(n);
    r.resize(n);
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        ans += r[i] - l[i] +1;
    }
    cout << ans << endl;
}

int main(){
    input();
    return 0;
}