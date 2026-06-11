#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    string frr;
    for(int i=0;i<s.size();i++)frr+='p';
    int counter=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='p'&&frr[i]=='p')counter++;
    }
    int k;

    if(s.size()%2==1)k=(s.size()/2)+1;
    else k=s.size()/2;
 //   k=k-counter;
   // cout<<k<<" "<<counter<<endl;
    for(int i=0;i<frr.size();i++)
    {
        if(frr[i]=='p'&&s[i]=='g')
        {
            frr[i]='g';
            k--;
            if(k<=0)break;
        }
    }
    //cout<<frr<<endl;
    int a=0,b=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='p'&&frr[i]=='g')a++;
        if(s[i]=='g'&&frr[i]=='p')b++;
    }
    cout<<max(0,b-a)<<endl;
}
