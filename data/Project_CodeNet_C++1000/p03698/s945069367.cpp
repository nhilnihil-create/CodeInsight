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
     string str;
     ll mx=0;
     map<char,ll>mp;
     cin>>str;
     for(int i=0;i<str.size();i++)
     {
         mp[str[i]]++;
         mx=max(mp[str[i]],mx);
     }
     if(mx==1)
        cout<<"yes"<<endl;
     else
        cout<<"no"<<endl;
}
