#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  int n,a,i,sum=0,sum1=0,l,s=0,dif,mx;
    vector<int>v;
    cin>>n;
    for(i=0;i<n;i++)
    {cin>>a;
    v.push_back(a);
    s+=a;

    }


      for(int i=n-1;i>=1;i--)
      {
          s-=v[i];
          sum+=v[i];
          dif=abs(s-sum);
          if(i==n-1){mx=dif;}
        else  {

            if(mx>dif)
            {
                mx=dif;
            }
          }
      }
cout<<mx<<endl;

}
