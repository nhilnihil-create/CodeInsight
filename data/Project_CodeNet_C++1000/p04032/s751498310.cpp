#include<bits/stdc++.h>
#define ll long long
const int mod=1e9+7;
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    s+='~';
    for(int i=0; i<s.size()-2; i++)
    {
        if(s[i]==s[i+1])
        {
            cout<<i+1<<" "<<i+2<<endl;
            return 0;
        }
        if(s[i]==s[i+2])
        {
            cout<<i+1<<" "<<i+3<<endl;
            return 0;
        }

    }
    cout<<-1<<" "<<-1<<endl;
}

