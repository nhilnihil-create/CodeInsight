#include <iostream>
#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int s[100003];

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        s[t]++;
        s[t + 1]++;
        s[t + 2]++;
    }
    cout << *max_element(s + 2, s + 100000) << endl;
    return 0;
}