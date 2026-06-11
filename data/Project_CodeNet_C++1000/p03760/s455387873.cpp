#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string O, E;
    cin >> O;
    cin >> E;
    for(int i = 0; i < O.size(); i++) {
        cout << O[i];
        if(i < E.size()) {
            cout << E[i];
        }
    }
    return 0;
}