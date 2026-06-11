#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        vector < pair < int, int > > a(n);
        for(int i = 0; i < n; i++){
                cin >> a[i].fi;
                a[i].se = i;
        }
        int A = 0, B = 0;
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++){
                if(a[i].se % 2 != i % 2){
                        if(i & 1) A += 1;
                        else B += 1;
                }
        }
        cout << max(A, B) << "\n";
}
