#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;

int main(){
    cin >> n >> m;
    if(n * 2 >= m) cout << min(n, m / 2);
    else{
        m -= (n * 2);
        ll Add = m / 4;
        cout << n + Add << endl;
    }
    return 0;
}
