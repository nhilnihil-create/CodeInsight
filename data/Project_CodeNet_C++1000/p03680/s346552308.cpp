#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, ans = 0, tmp = 0;
    cin >> n;
    vector<int> buttons(n);
    for (int i=0; i<n; i++) cin >> buttons[i];
    for (int i=0; i<n; i++){
        if (buttons[tmp] == 2){
            ans++;
            cout << ans << endl;
            return 0;
        } else{
            ans++;
            tmp = buttons[tmp] - 1;
        }
    }
    cout << -1 << endl;
    return 0;
}