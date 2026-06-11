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
  int n;cin>>n;
  ll cnt=0;
  bool flag[n+10]={};
  for(int i=0;i<n;i++){
    int t;cin>>t;
    if(t==i+1)
      flag[i]=false;
    else
      flag[i]=true;
  }
  for(int i=0;i<n;i++){
    if(i==n-1){
      if(!flag[i]){
	flag[i]=true;
	flag[i-1]=true;
	cnt++;
      }
    }else if(!flag[i]){
      flag[i]=true;
      flag[i+1]=true;
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
