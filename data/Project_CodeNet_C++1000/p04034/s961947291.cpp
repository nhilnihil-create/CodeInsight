#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<int> x(M),y(M);
    for (int i=0;i<M;i++){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
    }
    vector<int> count(N,1);
    vector<bool> red(N,false);
    red[0] = true;
    for (int i=0;i<M;i++){
        if (count[x[i]] == 1 && red[x[i]]) {
            count[x[i]]--;
            red[x[i]] = false;
            count[y[i]]++;
            red[y[i]] = true;
        } else if (count[x[i]] > 1 && red[x[i]]){
            count[x[i]]--;
            count[y[i]]++;
            red[y[i]] = true;
        } else {
            count[x[i]]--;
            count[y[i]]++;
        }
    }
    int ans = 0;
    for (int i=0;i<N;i++){
        if (red[i]) ans++;
    }
    cout << ans << "\n";
}