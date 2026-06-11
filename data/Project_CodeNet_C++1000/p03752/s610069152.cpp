#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  long long kotae=LLONG_MAX;
  for (int i = 0; i < (1 << n); i++) {
    int bit[15];
	for (int j = 0; j < n; j++){
      bit[j] = (i / (1 << j)) % 2;
    }
    long long sa=0;
    int kazu=1;
    int start=a[0];
    for(int j=1;j<n;j++){
      start=max(a[j-1],start);
      if(bit[j]==0)continue;
      if(bit[j]==1){
        kazu++;
        if(a[j]>start){
          start=a[j];
        }else{
          start++;
          sa+=start-a[j];
          //cout<<" sa:"<<start-a[j]<<endl;
        }
      }
    }
    //cout<<kazu<<" "<<sa<<endl;
    if(kazu>=k)kotae=min(kotae,sa);
  }
  cout<<kotae<<endl;
  return 0;
}
