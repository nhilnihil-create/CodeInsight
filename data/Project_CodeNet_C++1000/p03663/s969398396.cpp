#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll power(ll x, ll n){
    ll res = 1;
    for(int i = 0; i < n; i++) res *= x;
    return res;
}

int main()
{
    char ans;
    ll n;
    cout << "? 9" << endl;
    cin >> ans;
    int l;
    if(ans == 'Y'){
        n = power(10, 10);
        cout << "? " << n << endl;
        cin >> ans;
        if(ans == 'Y'){
            cout << "! 1" << endl;
            return 0;
        }
        for(l = 10; l >= 1; l--){
            n = power(10, l - 1);
            cout << "? " << n << endl;
            cin >> ans;
            if(ans == 'Y') break;
        }
    }
    else{
        for(l = 2; l < 10; l++){
            n = power(10, l) - 1;
            cout << "? " << n << endl;
            cin >> ans;
            if(ans == 'Y') break;
        }
    }
    ll s = 0;
    for(int i = l; i > 1; i--){
        n = s + power(10, i - 2) * 8;
        cout << "? " << n << endl;
        cin >> ans;
        if(ans == 'Y'){
            n = s + power(10, i - 2) * 9;
            cout << "? " << n << endl;
            cin >> ans;
            if(ans == 'Y') s += power(10, i - 2) * 9;
            else s += power(10, i - 2) * 8;
        }
        else{
            n = s + power(10, i - 2) * 4;
            cout << "? " << n << endl;
            cin >> ans;
            if(ans == 'Y'){
                n = s + power(10, i - 2) * 6;
                cout << "? " << n << endl;
                cin >> ans;
                if(ans == 'Y'){
                    n = s + power(10, i - 2) * 7;
                    cout << "? " << n << endl;
                    cin >> ans;
                    if(ans == 'Y') s += power(10, i - 2) * 7;
                    else s += power(10, i - 2) * 6;
                }
                else{
                    n = s + power(10, i - 2) * 5;
                    cout << "? " << n << endl;
                    cin >> ans;
                    if(ans == 'Y') s += power(10, i - 2) * 5;
                    else s += power(10, i - 2) * 4;
                }
            }
            else{
                n = s + power(10, i - 2) * 2;
                cout << "? " << n << endl;
                cin >> ans;
                if(ans == 'Y'){
                    n = s + power(10, i - 2) * 3;
                    cout << "? " << n << endl;
                    cin >> ans;
                    if(ans == 'Y') s += power(10, i - 2) * 3;
                    else s += power(10, i - 2) * 2;
                }
                else{
                    n = s + power(10, i - 2) * 1;
                    cout << "? " << n << endl;
                    cin >> ans;
                    if(ans == 'Y') s += power(10, i - 2) * 1;
                    else s += power(10, i - 2) * 0;
                }
            }
        }
    }
    for(int i = 8; i >= 0; i--){
        cout << "? " << s * 100 + i * 10 << endl;
        cin >> ans;
        if(ans == 'N'){
            cout << "! " << s * 10 + i + 1 << endl;
            return 0;
        }
    }
    cout << "! " << s * 10 << endl;
}