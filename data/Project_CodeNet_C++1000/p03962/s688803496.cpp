#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>

using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}


int main() {
  int A,B,C;
  cin>>A>>B>>C;
  if(A==B&&B==C&&C==A) cout<<1<<endl;
  else if(A!=B&&B!=C&&C!=A) cout<<3<<endl;
  else cout<<2<<endl;
}
