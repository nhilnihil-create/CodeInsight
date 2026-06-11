#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
string S;
    cin >> S;
    int n = 0, w = 0, s = 0, e = 0;
    for (int i = 0; i < (int)S.size(); ++i) {
        if (S[i] == 'N')
            n++;
        if (S[i] == 'S')
            s++;
        if (S[i] == 'W')
            w++;
        if (S[i] == 'E')
            e++;
    }
    if (n != s && min(n, s) == 0) {
        cout << "No"
             << "\n";
    } else if (w != e && min(w, e) == 0) {
        cout << "No"
             << "\n";
    } else {
        cout << "Yes"
             << "\n";
    }
    return 0;
}