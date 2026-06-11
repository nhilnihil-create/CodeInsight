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
  long long N,K;
  cin>>N>>K;
  long long X=K*pow(K-1,N-1);
  cout<<X<<endl;
}
