#include <iostream>
#include<bits/stdc++.h>
#include <string>
#define loop(i,n) for(int i=0;i<(int)n;i++)

using namespace std;

int main()
{
int n;
cin>>n;

int l;
cin>>l;

string s[n];

loop(i,n) cin>>s[i];

sort(s,s+n);

string ans;

loop(i,n) ans=ans+s[i];
cout<<ans;

}
