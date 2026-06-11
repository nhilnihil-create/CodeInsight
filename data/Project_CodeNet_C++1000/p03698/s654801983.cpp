#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> line(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        int num = s.at(i) - 'a';
        line.at(num)++;
        if (line.at(num) == 2)
        {
            puts("no");
            return 0;
        }
    }
    puts("yes");
}