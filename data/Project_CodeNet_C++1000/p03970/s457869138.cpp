#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    string S;
    string O = "CODEFESTIVAL2016";
    cin >> S;
    int cnt = 0;
    
    for (int i=0; i<16; i++) {
        if (S[i] != O[i]) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
}