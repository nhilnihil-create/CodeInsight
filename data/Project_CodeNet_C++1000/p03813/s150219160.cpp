#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "AtCoder Beginner Contest ";
    string b = "AtCoder Regular Contest";
    int s1 = a.size();
    int s2 = b.size();
    a[0] = toupper(a[0]);
    b[0] = toupper(b[0]);
    int x;
    cin >> x;
    if(x<1200)
    {

    for(int i =0; i<s1; i++)
    {
        if(a[i-1] == ' ')
            a[i] = toupper (a[i]);
    }
    cout << "ABC" <<endl;
    }
    else if(x>=1200)
    {
        for(int j =0; j<s2; j++)
    {
        if(b[j-1] == ' ')
            b[j] = toupper (b[j]);
    }
    cout << "ARC" <<endl;
    }
    return 0;
}
