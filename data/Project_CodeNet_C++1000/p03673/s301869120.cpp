#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int t = 0;
    if (n % 2)
    {
        // 奇数
        for (int i = n-1; i >= 0; i-=2 )
        {
            b[t] = a[i];
            t++;
        }
        for (int i = 1; i < n-1; i+=2)
        {
            b[t] = a[i];
            t++;
        }
        
    }
    else
    {
        for (int i = n-1; i > 0; i-=2 )
        {
            b[t] = a[i];
            t++;
        }
        for (int i = 0; i < n-1; i+=2)
        {
            b[t] = a[i];
            t++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << b[i];
        if (i != n-1)
        {
            cout << " ";
        }else{
            cout << endl;
        }
        
    }
    
    

}

int main() {
    solve();
    return 0;
}