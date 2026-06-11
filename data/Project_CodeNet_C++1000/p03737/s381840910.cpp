#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string c,a,b;
    cin >> a >> b >> c;
    char e = a.at(0);
    char f = b.at(0);
    char g = c.at(0);

    int n = (int)e-32;
    int m = (int)f-32;
    int o = (int)g-32;

    cout << (char)n << (char)m << (char)o << endl;


    
}