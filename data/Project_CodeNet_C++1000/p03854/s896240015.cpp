#include <bits/stdc++.h>
using namespace std;

string S;
string t[4] = {"maerd",
               "remaerd",
               "esare",
               "resare"};

int main()
{
    cin >> S;

    string s;
    for (int i = S.size()-1; i >=0; i--)
    {
        s += S[i];
        for (int j = 0; j < 4; j++)
        {
            if(s == t[j]) s = "";
        }
        
    }
    if(s == "") cout << "YES" << endl;
    else cout << "NO" << endl;
    
 
    return 0;
}
