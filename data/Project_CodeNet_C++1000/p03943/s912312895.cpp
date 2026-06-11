#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll A,B,C;
  cin>>A>>B>>C;
  if(A-B==C||B-A==C) printf("Yes\n");
  else if(C-A==B||A-C==B) printf("Yes\n");
  else if(C-B==A||B-C==A) printf("Yes\n");
  else cout<<"No"<<endl;
  return 0;
}
	
