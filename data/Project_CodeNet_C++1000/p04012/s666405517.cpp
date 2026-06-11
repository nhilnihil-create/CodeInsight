#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int a[30];
int main()
{
string w;
cin>>w;
for(int i=0;i<w.size();i++)
{
      a[w[i]-97]++;


}
int flag=0;
for(int i=0;i<26;i++)
{
    if(a[i]%2!=0)
    {
        flag=1;
        break;
    }
}
if(flag==0)
    cout<<"Yes"<<endl;
else cout<<"No"<<endl;


}
