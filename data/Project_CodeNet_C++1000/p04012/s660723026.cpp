#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
  int n,a[100],i,j,k;
  string s;
  cin>>s;
 n=s.size();
 // cout<<s[0]-'a'<<endl;
 for(i=0;i<26;i++){a[i]=0;}
  for(i=0;i<n;i++){a[s[i]-'a']++;}
  
  for(i=0;i<26;i++){if(a[i]%2!=0){cout<<"No";return 0;}}
  cout<<"Yes";
  
  return 0;
}