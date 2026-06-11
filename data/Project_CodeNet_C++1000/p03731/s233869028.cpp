#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, T;
    cin >> N >> T;
    vector<int> t(N + 1);
    for(int i = 0; i < N; i++){
        cin >> t.at(i);
    }
    t.at(N) = 2 * pow(10, 9) + 1;
    int ans = 0;
    for (int i = 0; i < N; i++){
        ans += min(T, t.at(i+1)-t.at(i));
    }
    cout << ans << endl;
}