#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  
  int n,i,l,j,k,p;

cin>>n>>k;
map<int,int>m;
for(i=0;i<k;i++)
{
   cin>>l;
   m[l]++;
}
while(1)
{p=n;
 while(p)
 {
     if(m[p%10])break;
     p/=10;
 }
 if(p==0)
 {
     cout<<n;return 0;
 }
  n++; 
}
}