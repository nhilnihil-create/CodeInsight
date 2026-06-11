#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    ll a, b, c;
    cin >> a >> b >> c;

    ll cnt = 0;
    map<int, int> mem;
    mem[a]++;
    mem[b]++;
    mem[c]++;

    ll a_temp, b_temp, c_temp;
    a_temp = a;
    b_temp = b;
    c_temp = c;

    while ((a%2==0) && (b%2==0) && (c%2==0)){
        a_temp /= 2;
        b_temp /= 2;
        c_temp /= 2;

        a = c_temp + a_temp;
        b = a_temp + b_temp;
        c = b_temp + c_temp;

        mem[a]++;
        mem[b]++;
        mem[c]++;

        if ((mem[a] < 4) && (mem[b] < 4) && (mem[c] < 4)){
            cnt++;
        }
        else{
            cout << -1 << endl;
            return 0;
        }

    }

    cout << cnt << endl;
    return 0;
}