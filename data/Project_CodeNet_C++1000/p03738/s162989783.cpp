#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  string s1, s2;
  cin>>s1>>s2;
  ll n1, n2;
  n1 = s1.size();
  n2 = s2.size();
  if(n1 == n2)
  {
  if(s1>s2) cout<<"GREATER"<<endl;
  else if(s1 == s2) cout<<"EQUAL"<<endl;
  else cout<<"LESS"<<endl;
  }
  else
  {
      if(n1>n2) cout<<"GREATER"<<endl;
      else cout<<"LESS"<<endl;
  }


return 0;
}

