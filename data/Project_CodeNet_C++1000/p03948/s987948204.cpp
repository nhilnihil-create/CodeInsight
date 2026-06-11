#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    vector<int> nm(n + 1);//i以降の最大
    for(int i = 0; i < n; i++)cin >> a[i];

    for(int i = n - 1; i >= 0; i--){
        nm[i] = max(a[i], nm[i + 1]);
    }

    int nax = 0;
    for(int i = 0; i < n; i++){
        nax = max(nax, nm[i] - a[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(nm[i] - a[i] == nax)ans++;
    }
    cout << ans << endl;

}