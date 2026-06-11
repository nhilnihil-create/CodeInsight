#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    vector<int> a(n); for(int i = 0; i < n; i++){cin >> a[i]; a[i]--;}

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[a[i]] == i)cnt++;
    }
    cout << cnt / 2 << endl;
}