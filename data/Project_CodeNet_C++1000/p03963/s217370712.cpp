#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int s=n-1;
  int total=k*pow(k-1,s);
  cout<<total<<endl;
  return 0;
}