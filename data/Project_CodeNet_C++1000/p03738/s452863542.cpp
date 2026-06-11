#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    if (s.size() > t.size())
    {
        puts("GREATER");
        return 0;
    }
    else
    {
        if (s.size() < t.size())
        {
            puts("LESS");
            return 0;
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s.at(i) > t.at(i))
                {
                    puts("GREATER");
                    return 0;
                }
                else
                {
                    if (s.at(i) < t.at(i))
                    {
                        puts("LESS");
                        return 0;
                    }
                }
            }
        }
    }
    puts("EQUAL");
}