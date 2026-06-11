#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;


int main(void)
{
    string s;
    cin >> s;

    string out = "";
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '0'){
            out.push_back('0');
        } else if(s[i] == '1'){
            out.push_back('1');
        } else {
            if(s.size() > 0){
                out = out.substr(0, out.size() - 1);
            }
        }
    }

    cout << out << endl;
    
    return 0;
}
