#include<iostream>
#include<vector>
#include<map>
#include<utility>
#define int long long
using namespace std;
main()
{
    //fast
    int tc=1,i,j,k;
//    cin>>tc;
    while(tc--)
    {
       int a,l;
       cin>>a>>l;
       int s=0;
       int aa[a];
       for(i=0;i<a;i++)
       {
           cin>>aa[i];
       }
       int in=-1,ok=1;
       vector<int>ind;
       for(i=0;i+1<a;i++)
       {
           if(aa[i]+aa[i+1]>=l)
            {
                in=i;
                break;
            }
       }
       if(in==-1)
        ok=0;
       for(j=a-1;j-1>in;j--)
        ind.push_back(j);
       for(i=0;i<=in;i++)
        ind.push_back(i+1);
        if(ok)
        {
            cout<<"Possible"<<endl;
            for(auto it : ind)
                cout<<it<<" ";
            cout<<endl;
        }
        else cout<<"Impossible"<<endl;



    }
}


