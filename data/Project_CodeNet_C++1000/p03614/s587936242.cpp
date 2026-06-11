#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        vector < int > a(n);
        int res = 0;
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        for(int i = 0; i < n; i++){
                if(a[i] == i + 1){
                        res += 1;
                        i += 1;
                }
        }
        cout << res << "\n";
}
