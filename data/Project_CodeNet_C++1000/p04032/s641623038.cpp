#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s;
    cin>>s;
    bool flag=0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
        {
            flag=1;
            cout<<i<<" "<<i+1<<endl;
            break;
        }
        else if(i>1 && s[i]==s[i-2])
        {
            flag=1;
            cout<<i-1<<" "<<i+1<<endl;
            break;
        }
    }
    if(flag==0)
        cout<<"-1 -1"<<endl;

    return 0;
}
