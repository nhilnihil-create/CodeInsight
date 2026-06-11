#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n;
    cin >> n;
    char c;
    int x=0,M=0;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c=='I')
        {
            x++;
        }
        else
        {
            x--;
        }
        M = max(x,M);
    }
    cout << M << endl;
}
