#include <bits/stdc++.h>
using namespace std;




int main(){
  int n;
  cin>>n;
  long long sum=0;
  vector<long long>b;
  for(int i=0;i<n;i++){
    long long a;
    cin>>a;
    b.push_back(a);
    sum+=a;
  }
  long long sum2=0;
  long long ans2=1000000000000000000;
  for(int i=0;i<n-1;i++){
    sum2+=b.at(i);
    sum-=b.at(i);
    ans2=min(ans2,abs(sum2-sum));
  }
  cout <<ans2;
}