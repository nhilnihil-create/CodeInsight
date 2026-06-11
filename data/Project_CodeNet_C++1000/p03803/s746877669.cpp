#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  a,b,w=0,n,i,c=0;
   cin>>a>>b;
   if(b==1 && a!=1) std::cout << "Bob" << '\n';
   else if(a==1 && b!=1) std::cout << "Alice" << '\n';
   else if(a>b) std::cout << "Alice" << '\n';
   else if(a<b) std::cout << "Bob" << '\n';
   else if(a==b) std::cout << "Draw" << '\n';


return 0;
}
