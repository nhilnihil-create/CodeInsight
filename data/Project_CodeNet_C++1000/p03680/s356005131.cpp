#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> lig(n+1);
    repe(i,1,n)
    {
        cin >> lig[i];
    }
    
    
    int lighting = 1;
    
    repe(i,1,n)
    {
        lighting = lig[lighting];

        if (lighting == 2) {
            cout << i;
            return 0;
        }


    }
    cout << -1;
}
