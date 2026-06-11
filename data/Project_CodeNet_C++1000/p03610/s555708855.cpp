#include <bits/stdc++.h>

using namespace std;

int main(){
    string L;
    string R = "";
    cin >> L;
    int i = 0;
    while (i < L.size()){
        R += L[i];
        i += 2;
    }
    cout << R << endl;
}