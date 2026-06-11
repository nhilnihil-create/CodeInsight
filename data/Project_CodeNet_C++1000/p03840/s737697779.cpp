#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long i ,o ,t ,j ,l ,s ,z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    if((i&1) == (j&1) && (i&1) == (l&1))
        cout << o+i+j+l << endl;
    else if(i&&j&&l)
        cout << o+max(i+j+l-(i&1)-(j&1)-(l&1) ,i+j+l-!(i&1)-!(j&1)-!(l&1)) << endl;
    else
        cout << o+(i+j+l-(i&1)-(j&1)-(l&1)) << endl;
}