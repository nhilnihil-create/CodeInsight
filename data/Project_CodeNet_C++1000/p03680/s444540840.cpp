#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0;
    int num = 1;
    while (cnt < n){
        num = a[num-1];
        cnt++;
        if (num==2){
            cout << cnt;
            return 0;
        }


    }
    cout << -1;

    return 0;
}