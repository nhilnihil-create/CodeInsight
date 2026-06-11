#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long a,b,c;
   cin>>a>>b>>c;
   if(c-b<=0) std::cout << "delicious" << '\n';
   else  if(c-b<=a) std::cout << "safe" << '\n';
   else std::cout << "dangerous" << '\n';
  return 0;
}
