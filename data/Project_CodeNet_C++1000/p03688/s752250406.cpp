#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <queue>
#include <deque>
using namespace std;
using ll=long long;
#define INF 2100000000

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());

  int n=a.at(N-1);
  if(a.at(0)==n){
    if(n==N-1||n<=N/2){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else if(a.at(0)+1!=n){
    cout<<"No"<<endl;
  }else{
    int count=lower_bound(a.begin(),a.end(),n)-a.begin();
    if(n<=count){
      cout<<"No"<<endl;
    }else if(2*(n-count)<=N-count){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
