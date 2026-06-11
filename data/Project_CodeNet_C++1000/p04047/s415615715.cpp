#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,s=0;
  cin>>n;
  vector<int>v(2*n);
  for(int i=0;i<2*n;i++)
  {
     cin>>v[i];

  }
  sort(v.begin(),v.end());
for(int i=0;i<2*n;i+=2)
 {
    
  s+=v[i];
}
cout<<s<<endl;

}