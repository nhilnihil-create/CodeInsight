#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i%2-1)
        {
            cout << s.at(i) ;
        }
        
    }
    cout << endl;
    

    return 0;
}