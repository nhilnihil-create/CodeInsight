#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;


int main(){
  LL n,l,t;
  cin >> n >> l >> t;
  vector<LL> left(n),right(n);
  LL x,w;
  LL leftcount=0,rightcount=0;
  bool zeroleft=false;
  for(int i=0;i<n;i++){
    cin >> x >> w;
    if(w==1){
      right[rightcount++]=x;
    }else{
      left[leftcount++]=x;
    }
  }
  LL num=leftcount*(t/l)+distance(left.begin(),lower_bound(left.begin(),left.begin()+leftcount,t%l))-(rightcount*(t/l)+rightcount-distance(right.begin(),lower_bound(right.begin(),right.begin()+rightcount,l-t%l)));
  // cout << distance(left.begin(),upper_bound(left.begin(),left.begin()+leftcount,t%l)) << endl;
  // cout << rightcount-distance(right.begin(),lower_bound(right.begin(),right.begin()+rightcount,l-t%l)) << endl;
  // cout << num << endl;
  vector<LL> pos(n);
  for(int i=0;i<rightcount;i++){
    right[i]=(right[i]+t%l)%l;
    pos[i]=right[i];
  }
  for(int i=0;i<leftcount;i++){
    left[i]=((left[i]-t%l)%l+l)%l;
    pos[i+rightcount]=left[i];
  }
  sort(pos.begin(),pos.end());
  vector<LL> ans(n);
  for(int i=0;i<n;i++){
    ans[((num+i)%n+n)%n]=pos[i];
  }
  for(int i=0;i<n;i++) cout << ans[i] << endl;
  return 0;
}
