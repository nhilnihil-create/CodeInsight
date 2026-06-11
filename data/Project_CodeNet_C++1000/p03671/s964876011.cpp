#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int ar[3];
  
  cin>>ar[0]>>ar[1]>>ar[2];
  
  sort(ar,ar+3);
  
  cout<<(ar[0]+ar[1]);
}
