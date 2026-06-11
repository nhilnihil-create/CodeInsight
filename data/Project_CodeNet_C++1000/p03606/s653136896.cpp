#include<iostream>
using namespace std;
int main()
{
    int n, a[100001], b[100001], p = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        p = p + (b[i] - a[i] + 1);
    }
    cout << p;
    return 0;
}