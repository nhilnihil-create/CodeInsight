#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

int main(){
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> ans(MAX+5, 0);
    for(int i = 0; i < n; i++){
        ans[l[i]]++;
        ans[r[i]+1]--;
    }

    for(int i = 1; i < MAX+3; i++){
        ans[i] += ans[i-1];
    }
    int ans2 = 0;
    for(int i = 1; i <= MAX; i++) ans2 += ans[i];
    cout << ans2 << endl;
    return 0;
}