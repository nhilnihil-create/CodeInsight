#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    char c;
    char d;
    cin >> c;
    d = c;
    int count = 0;
    while (cin >> c)
    {
        if(c!=d)
        {
            count++;
        }
        d=c;
    }
    cout << count << endl;
}