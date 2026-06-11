#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int a[26];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str w;
    cin>>w;

    for(int i=0;i<w.size();i++)a[w[i]-'a']++;

    bool ans=true;

    for(int i=0;i<26;i++)if(a[i]%2)ans=false;

    puts(ans?"Yes":"No");

    return 0;
}
