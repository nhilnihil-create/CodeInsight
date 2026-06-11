#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define precision(n) cout << fixed << setprecision(n);
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
    fast;
   string s;
   int w,p;
   cin>>s;
   for(int i=0;i<s.size();i++)
   {
       if(s[i]=='A')
       {
           p=i;
           break;
       }
   }
   for(int i=s.size()-1;i>=0;i--)
   {
       if(s[i]=='Z')
       {
           w=i;
           break;
       }
   }
   cout<<w-p+1<<endl;
    return 0;
}



