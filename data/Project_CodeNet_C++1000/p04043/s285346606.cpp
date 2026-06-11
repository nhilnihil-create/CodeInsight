#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, five = 0, seven = 0;
    cin >> a >> b >> c;

    if(a == 5)
        five++;
    if(b == 5)
        five++;
    if(c == 5)
        five++;

    if(a == 7)
        seven++;
    if(b == 7)
        seven++;
    if(c == 7)
        seven++;

    if(five == 2 && seven == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
