#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=10e9+7,OO=0x3f3f3f3f;
string s;
int main ()
{
    cin>>s;
    for(int i=0;i<s.size();i++){
        s[i]==','?cout<<" ":cout<<s[i];
    }

    return 0;
}