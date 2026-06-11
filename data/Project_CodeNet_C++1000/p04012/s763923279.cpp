#include<bits/stdc++.h>
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{

    string s;
    cin >> s;
    map<char,int>mp;
    int m=0;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if((it->second)%2!=0)
        {
            m++;
        }
    }
    if(m>0)
    {
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }


}