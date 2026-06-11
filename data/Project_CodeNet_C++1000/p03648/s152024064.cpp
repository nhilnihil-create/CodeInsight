#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k;
  cin>>k;
  cout<<50<<endl;
  long long a,b;
  a=k%50;
  b=k/50;
  for(int i=0;i<a;i++){
    cout<<100-a+b<<' ';
  }
  for(int i=0;i<49-a;i++)cout<<49-a+b<<' ';
  cout<<49-a+b<<endl;
}
