 #include<bits/stdc++.h>
#include<ctime>
 using namespace std;
int n,m;
set<int>q;
 int dis(int x1,int y1,int x2,int y2)
 {
     return abs(x1-x2)+abs(y1-y2);
}
int a1[10000],b1[100000],a2[10000],b2[100000];
 int main()
 {
     cin>>n>>m;
     for(int i=1;i<=n;i++)
     {
         cin>>a1[i]>>b1[i];
     }
    for(int i=1;i<=m;i++)
     {
        cin>>a2[i]>>b2[i];
    }
    for(int i=1;i<=n;i++)
    {
         int pos;
       int Max=(1<<31)-1;
         for(int j=1;j<=m;j++)
      {
             int ans=dis(a1[i],b1[i],a2[j],b2[j]);
            //cout<<ans<<endl;
             if(ans<Max)
             {
                 pos=j;
                // cout<<pos<<endl;
                 Max=ans;
             }
         }
        cout<<pos<<endl;
     }
     return 0;
 }