#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;

    map<char,int> m;
    if(s[0]=='B'){m['B']=0;m['W']=1;}
    else{m['B']=1;m['W']=0;}

    int cnt=0;
    for(int i=0;i<s.size();i++)if(cnt%2!=m[s[i]]%2)cnt++;

    cout<<cnt<<"\n";

    return 0;
}
