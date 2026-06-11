#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int n;
  cin>>n;
  int i=1;
  if(n==1)cout<<1<<endl;
  else{
    while(i*(i+1)/2<n)
      i++;
    for(int j=1;j<=i;j++){
      if(((i*(i+1)/2)-n)!=j)
	cout<<j<<endl;
    }
  }
  return 0;
}
