#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    
    if (n == 1){
        if (a==b){
            cout << "1" << endl;
            return 0;
        }
        else{
            cout << "0" << endl;
            return 0;
        }
    }
    
    if (b < a){
        cout << "0" << endl;
        return 0;
    }
    
    ll c = a*(n-1) + b;
    ll d = b*(n-1) + a;
    
    cout << d - c + 1 << endl;
    return 0;
}

