#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    map<char,int>mp;
    string s;
    cin >> s;
    bool mk = 0;
    for(int i=0; i<s.size(); i++)
        mp[s[i]]++;

    for(char i = 'a'; i<='z'; i++)
    {
        if(mp[i]%2){mk = 1;break;}
    }
    if(!mk)cout << "Yes" << endl;
    else cout << "No" << endl;

 }
