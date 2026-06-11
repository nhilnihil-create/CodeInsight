#include<bits/stdc++.h>
#include <vector>
#define endl '\n';
using namespace std;

int main()
{
    string x; cin >> x;
    int a = x.find('A');
    int z, sz = (int)x.size();
    for(int i = sz - 1 ; i > a ; --i)
    {
        if (x[i] == 'Z') { z = i; break; }
    }
    cout << z - a + 1;
    return 0;
}