#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, x; cin >> n >> x;
    if(x == 2 * n - 1 || x == 1){
        cout << "No" << endl;
        return 0;
    }

    if(n == 2) {
        cout << "Yes" << endl;
        cout << 1 << " " << 2 << " " << 3 << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<int> a(2 * n - 1);
    vector<bool> used(2 * n);
    a[n - 1] = x;
    a[n - 2] = x - 1;
    a[n] = x + 1;
    used[a[n - 1]] = true, used[a[n]] = true, used[a[n - 2]] = true;
    if(x <= n)a[n - 3] = x + 2, used[x + 2]  = true;
    else a[n + 1] = x - 2, used[x - 2] = true;

    vector<int> num;
    for(int i = 1; i <= 2 * n - 1; i++) {
        if(used[i])continue;
        num.push_back(i);
    }
    for(int i = 0; i < 2 * n - 1; i++) {
        if(a[i])continue;
        a[i] = num.back();
        num.pop_back();
    }
    for(auto i : a)cout << i << endl;
}