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
         if(a<3200)
         arr[a/400]++;
         else
            arr[8]++;
     }
     int mn=0,mx=0,sum;
     for(int i=0;i<=7;i++)
     {
         mx+=(arr[i]>0);
     }
     mn=mx;
     mn=max(mn,1);
     cout<<mn<<" "<<mx+arr[8]<<endl;
}

