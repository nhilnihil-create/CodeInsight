#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1<<30;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    int amin = INF, dmax = 0, ans = 0;
    for(int i=0;i<N;i++){
        if(a[i]-amin > dmax){
            dmax = a[i] - amin;
            ans = 1;
        }
        else if(a[i]-amin == dmax){
            ans++;
        }
        amin = min(amin, a[i]);
    }
    cout << ans << endl;
    return 0;
}
