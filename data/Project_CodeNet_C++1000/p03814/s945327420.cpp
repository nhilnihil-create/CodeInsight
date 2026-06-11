#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    int a=0, b=0;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='A') 
        {
            a = i;
            break;
        }
    }
   
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='Z') b = max(b, i);
    }

    cout << b-a+1 << endl;  
    return 0;
}