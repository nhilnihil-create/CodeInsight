#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*
ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
*/
int main()
{
     ll t,arr[15],a;
     for(int i=0;i<15;i++)
        arr[i]=0;
     cin>>t;
     for(int i=0;i<t;i++)
     {
         cin>>a;
         if(a>=1 && a<=399)
         {
             arr[0]++;
         }
         else if(a>=400 && a<=799)
         {
             arr[1]++;
         }
         else if(a>=800 && a<=1199)
         {
             arr[2]++;
         }
         else if(a>=1200 && a<=1599)
         {
             arr[3]++;
         }
         else if(a>=1600 && a<=1999)
         {
             arr[4]++;
         }
         else if(a>=2000 && a<=2399)
         {
             arr[5]++;
         }
         else if(a>=2400 && a<=2799)
         {
             arr[6]++;
         }
         else if(a>=2800 && a<=3199)
         {
             arr[7]++;
         }
         else
            arr[8]++;
     }
     int mn=0,mx=0;
     for(int i=0;i<=7;i++)
     {
         mn+=(arr[i]>0);
         mx+=(arr[i]>0);
         //cout<<arr[i]<<endl;
     }
     mn=max(mn,1);
     cout<<mn<<" "<<mx+arr[8]<<endl;
}

