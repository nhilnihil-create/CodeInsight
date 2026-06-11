#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,l,cnt=0;
    string s;
    cin>>s;
    l=s.size();
    for(i=0; i<l; i++)
    {
        for(j=0; j<l; j++)
        {
            if(s[i]==s[j])
            {
                n++;
            }
        }
        if(n%2==0)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    if(cnt==l)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}
