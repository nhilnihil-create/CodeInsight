#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(arr,v) memset(arr,v,sizeof(arr))
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     string s1,s2;
     cin>>s1>>s2;
     if(s1.size()>s2.size())
        cout<<"GREATER";
     else if(s1.size()<s2.size())
        cout<<"LESS";
     else
     {
         ll cnt=0;
         for(int i=0;i<s1.size();i++)
         {
             if(s1[i]>s2[i])
             {
                 cnt=10;
                 cout<<"GREATER";
                 break;
             }
             if(s1[i]<s2[i])
             {
                 cnt=10;
                 cout<<"LESS";
                 break;
             }
         }
         if(cnt==0)
            cout<<"EQUAL";
     }
     cout<<endl;
}
