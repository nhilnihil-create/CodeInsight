#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
using namespace std;
#define MAX 300000
typedef long long ll;



int main(){
  ll X;
  cin>>X;
  ll sum=0,i;

  for(i=1;sum<X;i++){
    sum+=i;
  }
  cout<<i-1<<endl;
}
