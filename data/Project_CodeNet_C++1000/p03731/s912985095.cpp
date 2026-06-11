#include<iostream>
#include<string>

#define ll long long

using namespace std;

int main(){
    int n, T, a, _t, t;
    ll s;

    cin >> n >> T;
    cin >> _t;

    s = T;
    for(int i = 0; i < n-1; i++){
        cin >> t;
        a = t - _t;
        _t = t;
        s += (a > T) ? T : a;
    }

    cout << s << endl;
}