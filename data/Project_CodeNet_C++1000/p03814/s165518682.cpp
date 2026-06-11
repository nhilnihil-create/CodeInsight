#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int begin;
    int end;
    int ans;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s.at(i) == 'A')
        {
            begin = i;
            break;
        }
        
    }
    for (size_t i = begin; i < s.size(); i++)
    {
        if (s.at(s.size()+begin-i-1) == 'Z')
        {
            end = s.size()+begin-i;
            break;
        }
        
    }
    cout << end - begin << endl;

    return 0;
}