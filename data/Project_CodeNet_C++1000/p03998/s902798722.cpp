#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,string> mp;
    cin>>mp['a']>>mp['b']>>mp['c'];
  //  cout<<mp['a']<<' '<<mp['b']<<' '<<mp['c']<<endl;
    char ch,p;
    ch=mp['a'][0];
    mp['a'].erase(mp['a'].begin());
    while(1)
    {
       // cout<<ch<<endl;
        p=ch;
        if(mp[ch].empty())
        {
            cout<<(char)toupper(ch)<<endl;
            break;
        }
        ch=mp[ch][0];
        mp[p].erase(mp[p].begin());
    }
    return 0;
}
