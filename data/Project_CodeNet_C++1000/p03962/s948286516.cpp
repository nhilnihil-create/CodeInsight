#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int32_t main()
{
 IOS;
  int a,b,c;
  cin>>a>>b>>c;
  set<int>s;
  s.insert(a);
  s.insert(b);
  s.insert(c);
  cout<<s.size()<<endl;
  
  return 0;
}