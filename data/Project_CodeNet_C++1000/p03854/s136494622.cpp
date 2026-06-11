#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> vec = {
    "dreamer",
    "dream",
    "eraser",
    "erase"};

string string_check(int start, string s)
{
    for (int i = 0; i < 4; ++i)
    {
        if (vec[i] == s.substr(start, vec[i].length()))
        {
            if (start + vec[i].length() == s.length())
                return "YES";
            if (string_check(start + vec[i].length(), s) == "YES")
                return "YES";
        }
    }
    return "NO";
}
int main(void)
{
    string S;
    cin >> S;
    int count = 0;

    cout << string_check(0, S) << "\n";
}