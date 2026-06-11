#include<bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define sloop(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mn, mx, temp, count = 0;
    cin >> n;
    vector<int>def(8, 0);
    loop(i, n) {
        cin >> temp;
        if(temp >= 1 && temp <= 399) def[0] = 1;
        else if(temp >= 400 && temp <= 799) def[1] = 1;
        else if(temp >= 800 && temp <= 1199) def[2] = 1;
        else if(temp >= 1200 && temp <= 1599) def[3] = 1;
        else if(temp >= 1600 && temp <= 1999) def[4] = 1;
        else if(temp >= 2000 && temp <= 2399) def[5] = 1;
        else if(temp >= 2400 && temp <= 2799) def[6] = 1;
        else if(temp >= 2800 && temp <= 3199) def[7] = 1;
        else count++;
    }
    mn = 0;
    loop(i, 8) mn += def[i];
    mx = mn + count;
    if(!mn && count) mn++;
    cout << mn << " "<<  mx << endl;
    return 0;
}
