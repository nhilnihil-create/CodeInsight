#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string w;

    cin >> w;

    map <char, int> mp;
    map <char, int> :: iterator it;

    set <char> s;

    for(int i=0; i<w.size(); i++)
    {
        mp[w[i]]++;
        s.insert(w[i]);
    }

    int count1 = 0;


    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if(it->second > 0 && it->second%2 == 0)
        {
            count1++;
        }
    }

    if(count1 == s.size())
    {
        cout << "Yes";
    }

    else
    {
        cout << "No";
    }



}



