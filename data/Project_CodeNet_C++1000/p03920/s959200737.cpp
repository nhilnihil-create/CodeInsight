#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans;
    int sum = 0;
    
    for(int i = 1; i <= n; ++i) {
        if(sum + i < n) {
            ans.push_back(i);
            sum += i;
        } else {
            if(sum + i == n) {
                ans.push_back(i);
                break;
            } else {
                int dif = sum + i - n;
                ans[dif - 1] = i;
                break;
            }
        }
    }

    for(auto temp : ans)
        cout << temp << "\n";
}