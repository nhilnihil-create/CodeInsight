#include <iostream>  
#include <string.h> 
using namespace std;
int main() {
    int x, y=0,z=0; cin >> x; 
    string s;
    cin >> s;
    for (int i=0;i<x;i++){
        if (s[i] == 'I')
            y++;
        else 
            y--;

        if (y>z)
        z = y;
        
    
    }
    cout << z;
    return 0;
}

