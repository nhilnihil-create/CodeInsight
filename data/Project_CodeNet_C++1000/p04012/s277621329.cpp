#include<bits/stdc++.h>
using namespace std;
int main()
{
    string w;
    cin>>w;
    int l;
    l=w.size();
    if(l%2!=0)
    {
        cout<<"No"<<"\n";
    }
    else
    {   int c=0;
        for(int i=0;i<l;i++)
        {
            for(int j=0;j<l;j++)
            {
                if(w[i]==w[j])
                {
                   c++;
                }
            }
            if(c%2!=0)
            {
               cout<<"No"<<"\n";
               break;
            }
        }
        if((c%2==0)&&(c>0))
        {
            cout<<"Yes"<<"\n";
        }
    }


return 0;}
