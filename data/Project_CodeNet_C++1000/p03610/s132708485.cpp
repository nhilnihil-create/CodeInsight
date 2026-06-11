#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    string s;
    cin >> s;
    for (size_t i = 0; i < (s.size()+1)/2; i++)
    {
        cout << s.at(2*i);
    }
    cout << endl;
}