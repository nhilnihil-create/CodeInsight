#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    map<char,int> kosuu;
    char c;
    while (cin >> c)
    {
        kosuu[c]++;
    }
    for (auto &&e : kosuu)
    {
        if (e.second > 1)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}
