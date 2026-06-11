#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  
 ll n,i,j=0,sm1=0;
 string s;
 cin>>s;
 n=s.size();

map<char,int>m;
for(i=0;i<n;i++)m[s[i]]++;

for(auto it:m)
{
    if(it.second%2)
    {
        cout<<"No";
        return 0;
    }
}
cout<<"Yes";

}