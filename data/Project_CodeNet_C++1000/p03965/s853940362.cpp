#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s;

    cin >> s;

    int pn = 0;

    for(int i = 0; i < s.size(); ++i)
    {   
        if(s[i] == 'p') ++pn;
    }
    int n = s.size()/2;

    cout << n - pn << endl;


    return 0;
}

