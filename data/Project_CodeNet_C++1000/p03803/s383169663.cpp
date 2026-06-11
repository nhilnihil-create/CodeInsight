#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll A,B;
  cin>>A>>B;
  if(A==B) cout<<"Draw"<<endl;
  else if((A>B&&B!=1)||A==1) cout<<"Alice"<<endl;
  else cout<<"Bob"<<endl;
  return 0;
}
	
