#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    string a;
    getline(cin, a);
    vector<ll> x(500, 0);
    for (int i = 0; i < a.size(); i++)
        x[a[i]]++;
    
    ll res = a.size()*(a.size() + 1)/2 + 1;
    for (int i = 0; i < 500; i++)
        res -= x[i]*(x[i] + 1)/2;
    
    cout << res << endl;
    return 0;
}
