#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    int x=3;
    set<int> S;
    while(x--){
        cin >> t;
        S.insert(t);
    }
    cout << S.size();
 
    return 0;
}
