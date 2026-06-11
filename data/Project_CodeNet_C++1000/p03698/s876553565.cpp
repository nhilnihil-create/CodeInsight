#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int a[30];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;
    cin>>s;

    for(int i=0;i<s.size();i++)a[s[i]-'a']++;

    bool ans=true;

    for(int i=0;i<30;i++)if(a[i]>1)ans=false;

    puts(ans?"yes":"no");

    return 0;
}
