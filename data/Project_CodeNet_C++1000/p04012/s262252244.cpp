#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,j,k,cnt=0,flag=0;
    int n=s.length();
    sort(s.begin(),s.end());
    for(i=0;i<n;i++)
    {
        cnt=1;
        for(j=i+1;j<n;j++)
        {
            if(s[i]==s[j])
                cnt++;
            else
                break;
        }
        if(cnt%2!=0)
        {
            flag=1;
            break;
        }
        i=j-1;

    }
    if(flag==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
