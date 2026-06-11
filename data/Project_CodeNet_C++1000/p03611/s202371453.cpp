#include <bits/stdc++.h>
using namespace std;
int p[100003];
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int i;
        cin >>i;
        p[i]++;
        p[i + 1]++;
        p[i + 2]++;
    }
    cout << *max_element(p + 2, p + 100000) << endl;
    return 0;
}