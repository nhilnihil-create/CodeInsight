#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     string str;
     cin>>str;
     ll n=str.size(),cnt=0;
     n-=2;
     while(n>=0)
     {
         string str2,str3;
         for(int i=0;i<n/2;i++)
            str2+=str[i];
         for(int i=(n/2);i<n;i++)
            str3+=str[i];
        //cout<<str2<<" "<<str3<<endl;
         if(str2==str3)
         {
             cout<<n<<endl;
             cnt=10;
             break;
         }
         n-=2;
     }
     if(cnt==0)
        cout<<"0"<<endl;
}
