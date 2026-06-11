#include<bits/stdc++.h>
using namespace std;
int N,A,B;
vector<long long> h(100009);
long long lb=-1,ub=20000000000;

bool C(long long x){
  long long cnt=0;
  for(int i=0;i<N;i++){
    if(h[i]-x*B>0){
      long long a=h[i]-x*B;
      cnt+=(a+A-B-1)/(A-B);
    }
  }
  return cnt<=x;
}

int main(){
  cin >> N >> A >> B;
  for(int i=0;i<N;i++)cin >> h[i];
  while(ub-lb>1){
    long long mid=(ub+lb)/2;
    if(C(mid))ub=mid;
    else lb=mid;
  }
  cout << ub << endl;
}