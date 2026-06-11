#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int l=s.length();
    vector<int>res;
    for(int i=0; i<l; i++)
    {
        if(s[i]=='0')
        {
            res.push_back(0);
        }
        else{
            if(s[i]=='1')
                res.push_back(1);
            else{
                if(!res.empty())
                    res.pop_back();
            }
        }
    }
    for(int v :res) cout<<v;
}
