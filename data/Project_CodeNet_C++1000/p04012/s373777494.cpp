//Bismillahir Rahmanir Rahim
//In the name of Allah the Most Merciful
//Astagfirullahil laji Rabbi Minkulli Jamio
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
int i,j,k;
main()
{
  map<char,int> m;
  string s;
  cin>>s;
  for(i=0;i<s.length();i++)
  {
      m[s[i]]++;
  }
  int p=0;
  for(char c='a';c<='z';c++)
  {
      if(m[c]%2!=0)
      {
          p=1;
      }
  }
  if(p) cout<<"No"<<endl;
  else
  cout<<"Yes"<<endl;

}
