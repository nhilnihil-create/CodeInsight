#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int cnt = 0, ans =1;
    for (int i=1; i<= N; ++i){
        if (pow(2, (int)log2(i))==i) ans = i;
    }
    cout << ans << endl;
    return 0;
}