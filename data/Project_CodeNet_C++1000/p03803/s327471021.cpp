#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B;
    int c =0;
    int d = 0;
    cin >> A;
    cin >> B;
    int str[] = {2,3,4,5,6,7,8,9,10,11,12,13,1};
    int s = sizeof(str)/sizeof(int);

    for(int i=0; i<s; i++)
    {
        if(str[i] == A)
            c = i;

    }

    for(int j= 0; j<s; j++)
    {
        if(str[j] == B)
            d = j;
    }

    if(c>d)
    {
        cout << "Alice" <<endl;
    }
    else if(d>c)
    {
        cout<< "Bob" <<endl;
    }
    else if(c ==d)
    {
        cout <<"Draw" <<endl;
    }
    return 0;
}

