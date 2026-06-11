#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100003];

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int t;
        cin >> t;
        a[t]++;
        a[t + 1]++;
        a[t + 2]++;
    }
    cout << *max_element(a + 2, a + 100000) << endl;
    return 0;
}