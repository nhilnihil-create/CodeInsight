#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int h,w;
    cin >> h >> w;
    string x[h];

    for (int i = 0; i < h; i++)
    {
        cin >> x[i];
        
    }

    for (int i = 0; i < w+2; i++)
    {
        cout << '#';
    }
    cout << endl;
    

    for (int i = 0; i < h; i++)
    {
        cout << '#' << x[i] << '#';
        cout << endl;
    }
   
    for (int i = 0; i < w+2; i++)
    {
        cout << '#';
    }
    cout << endl;

    return 0;
}