#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<int>());
    for(int i = 1; i <= n; i++) {
        if(a[i + 1] < i + 1) {
            int j = i + 1;
            for(; a[j] == i; j++);
            int tmp1 = a[i] - i + 1;
            int tmp2 = j - i;
            if((tmp1 & 1) && (tmp2 & 1)) {
                cout << "Second" << endl;
            }
            else {
                cout << "First" << endl;
            }
            break;
        }
    }
    
    return 0;
}
