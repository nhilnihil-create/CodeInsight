#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin >> s;
    int len=s.size();
    if(s[0]==s[len-1])
    {
        if(len%2==1) cout << "Second\n";
        else cout << "First\n";
    }
    else
    {
        if(len%2==1)cout << "First\n";
        else cout << "Second\n";
    }
}