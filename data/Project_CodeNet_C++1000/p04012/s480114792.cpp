#include<bits/stdc++.h>
#define ll long long
using namespace std;
int d[256];
int main()
{
string s;
cin>>s;
for(auto i:s)
{d[i]++;}
for(auto i:d)if(i&1)return 0&puts("No");
puts("Yes");

}