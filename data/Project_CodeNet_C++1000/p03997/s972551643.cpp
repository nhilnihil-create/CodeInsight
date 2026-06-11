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
  int a,b,h;
  cin>>a>>b>>h;
  cout<<(a+b)*h/2<<endl;
}
