#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    string s;
    cin >> s;
    set<char> st;
    for (auto c : s)
        st.insert(c);
    if (st.size() == 2)
    {
        puts("Second");
        return 0;
    }

    if (s.front() == s.back())
    {
        if (s.size() % 2 == 0)
        {
            puts("First");
        }
        else
        {
            puts("Second");
        }
    }
    else
    {
        if (s.size() % 2 == 0)
        {
            puts("Second");
        }
        else
        {
            puts("First");
        }
    }
}