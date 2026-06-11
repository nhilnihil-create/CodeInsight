#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144;
vector<int64_t> seg(MAX_N*2-1);
int64_t qu(int a,int b,int k,int l, int r){
  if(r<=a||b<=l){
    return MAX_N;
  }
  else if(a<=l&&r<=b){
    return seg[k];
  }
  else{
    int64_t X=qu(a,b,k*2+1,l,(l+r)/2);
    int64_t Y=qu(a,b,k*2+2,(l+r)/2,r);
    return min(X,Y);
  }
}


int main() {
  int64_t N,Z=0;
  cin>>N;
  for(int i=0;i<N;i++){
    int64_t a;
    cin>>a;
    seg[MAX_N+i]=a;
  }
  for(int i=MAX_N-2;i>=0;i--){
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
  }
  for(int64_t i=0;i<N;i++){
    int64_t a=seg[i+MAX_N];
    int64_t L=0,R=i+1;
    while(R-L>1){
      int64_t D=(L+R)/2;
      int64_t C=qu(D,i+2,0,0,MAX_N);
      if(C==seg[i+MAX_N]){
        R=D;
      }
      else{
        L=D;
      }
    }
    a*=(i+1-L);
    L=i+2,R=MAX_N;
    while(R-L>1){
      int64_t D=(L+R)/2;
      int64_t C=qu(i+1,D,0,0,MAX_N);
      if(C==seg[i+MAX_N]){
        L=D;
      }
      else{
        R=D;
      }
    }
    a*=(R-i-2);
    Z+=a;
  }
  cout<<Z<<endl;
}

