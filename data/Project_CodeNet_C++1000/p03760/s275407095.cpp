#include<bits/stdc++.h>
using namespace std;

int main()
{
  string O,E;cin>>O>>E;string S;
  for(int i=0;i<(int)E.size();i++){S+=O[i];S+=E[i];}
  if(O.size()>E.size())S+=O[O.size()-1];
  cout<<S; 
}