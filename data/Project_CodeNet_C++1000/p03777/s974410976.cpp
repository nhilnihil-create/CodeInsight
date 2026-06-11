#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    char a, b;
    cin >> a >> b;
    if(a == 'H'){
        cout << b << endl;
    }else {
        cout << (b == 'H' ? 'D' : 'H') << endl;
    }
}