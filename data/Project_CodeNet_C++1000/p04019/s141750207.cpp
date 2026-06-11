#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int N, S, W, E = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'N') N++;
        if (s[i] == 'S') S++;
        if (s[i] == 'W') W++;
        if (s[i] == 'E') E++;
        i++;
    }
    
    if ( (N > 0 && S > 0) && (W == 0 && E == 0))
        cout << "Yes" << endl;
    else if ((W > 0 && E > 0) && (N == 0 && S == 0))
        cout << "Yes" << endl;
    else if (N > 0 && S > 0 && W > 0 && E > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}