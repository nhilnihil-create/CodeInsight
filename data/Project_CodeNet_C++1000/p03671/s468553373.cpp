#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int sum1=a+b;
  int sum2=a+c;
  int sum3=b+c;
  int minprice=min(sum1,min(sum2,sum3));
  cout<<minprice<<endl;
}
