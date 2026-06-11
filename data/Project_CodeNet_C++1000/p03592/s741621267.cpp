#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m, k;
    bool a = false;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= m; j++){
            sum = (n - i) * j + (m - j)* i;
            if(sum == k)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << (k == n * m ? "Yes":"No") << endl;
}