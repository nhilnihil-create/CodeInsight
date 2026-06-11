#include<iostream>
using namespace std;
int main()
{
    int n, k, a[55], s = 0, b;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] > a[j])
            {
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }

    for(int i = 0; i < k; i++)
    {
        s = s + a[i];
    }

    cout << s;
}