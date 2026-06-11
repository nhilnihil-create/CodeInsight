#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len, target;
    cin >> len >> target;
    vector<int> arr(len);
    set<int> seen;
    bool match = false, big = false;
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
        if(seen.count(target - arr[i])) {
            match = true;
        }
        if(arr[i] > target) {
            big = true;
        }
        if((match && big) || arr[i] == target) {
            cout << "POSSIBLE";
            return 0;
        }
        seen.insert(arr[i]);
    }
    cout << "IMPOSSIBLE";
}