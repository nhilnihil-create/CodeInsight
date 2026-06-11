#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
long p = 1000000007;
int main()
{
    queue<char> a,b,c;
    string s,t,u;
    cin >> s >> t >> u;
    for (auto &&e : s)
    {
        a.push(e);
    }
    for (auto &&e : t)
    {
        b.push(e);
    }
    for (auto &&e : u)
    {
        c.push(e);
    }
    char next = 'a';
    while (true)
    {
        if (next=='a')
        {
            if(a.empty())
                break;
            next = a.front();
            a.pop();
        }
        if (next=='b')
        {
            if(b.empty())
                break;
            next = b.front();
            b.pop();
        }
        if (next=='c')
        {
            if(c.empty())
                break;
            next = c.front();
            c.pop();
        }
    }
    cout << (char)(next+'A'-'a') << endl;
}