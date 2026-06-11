#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int mojisuu =0;
    mojisuu = s.size();
    char saisho, owari;
    saisho = s.at(0);
    mojisuu--;

    owari = s.at(mojisuu);
    mojisuu--;

    cout << saisho << mojisuu << owari << endl;
    
    
    
}