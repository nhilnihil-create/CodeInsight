#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1[] = {1,3,5,7,8,10,12};
    int a2[] = {4,6,9,11};
    int a, b, c1 = 0, c2 = 0;
    cin >> a >> b;

    for(int i = 0; i < 7; i++)
    {
        if(a1[i] == a || a1[i] == b) c1++;
    }
    for(int i = 0; i < 4; i++)
    {
        if(a2[i] == a || a2[i] == b) c2++;
    }

    if(a == 2 && b == 2) cout << "Yes" << endl;
    else if(c1 == 2 || c2 == 2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}