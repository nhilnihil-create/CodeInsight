#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,a,b;
    string str[101];
    string s1,s2;
    cin>>a>>b;
    for(i=0;i<a;i++)
        cin>>str[i];
    for(i=0;i<a;i++)
    {
        for(j=i+1;j<a;j++)
        {
            if(str[i]>str[j])
            {
                s1=str[i];
                str[i]=str[j];
                str[j]=s1;
            }
        }
    }
    for(i=0;i<a;i++)
        s2=s2+str[i];
    cout<<s2<<endl;
    return 0;
}
