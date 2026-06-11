#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    string res;
    int size = s.size();

    for(int i=0; i<size; i++)
    {
        if(s[i] != 'B')
        {
            res.push_back(s[i]);
        }
        else
        {
            res = res.substr(0,res.size()-1);
        }
    }

    cout<<res<<endl;
}
