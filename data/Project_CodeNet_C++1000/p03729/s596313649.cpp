#include<bits/stdc++.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    int len1,len2,len3;
    len1= a.size();
    len2= b.size();
   (a[len1-1]==b[0] && b[len2-1]==c[0])? cout<<"YES":cout<<"NO";
}