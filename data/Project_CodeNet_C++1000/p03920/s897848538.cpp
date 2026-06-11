#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#define pb push_back
#define mod 1000000007
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;

int main(void){
  int n;
  cin>>n;
  int i;
  for(i=1;i<n;i++){
    if(i*(i+1)/2 >= n) break;
  }
  while(i>0){
    if(n-i>=0) {cout<<i<<endl;n-=i;}
    i--;
  }
  return 0;
}
