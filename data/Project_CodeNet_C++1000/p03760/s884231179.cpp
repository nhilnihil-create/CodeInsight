#include<bits/stdc++.h>
using namespace std;

int main()
{
    string o , e;
    cin>>o>>e;
    string ans;

    int index1 =0 , index2 =0;
    int len = o.length() + e.length();
    for(int i=1;i<=len;i++)
    {
        if( i%2==1)
        {
            ans.push_back(o[index1]);
            index1++;
        } else
        {
            ans.push_back( e[index2]);
            index2++;
        }
    }
    cout<<ans;
}