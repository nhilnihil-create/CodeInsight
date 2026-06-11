#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for(int T = 0; T < t ; T++){
       ll a, b, x;
       cin >> a >> b >> x;
       ll arem = a%x, brem = b%x;
       a /= x;
       b /= x;
       if(arem == 0 && brem == 0)
            std::cout << b - a + 1<< std::endl;
       else if(arem == 0)
           cout << b - a + 1 << endl;
        else
            cout << b - a  << endl;
    }
    return 0;
}