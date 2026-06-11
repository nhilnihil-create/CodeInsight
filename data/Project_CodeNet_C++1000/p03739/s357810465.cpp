#include <iostream>
#include <vector>
using namespace std;
long long f(vector<int>a, int sign){
  long long ans = 0;
  if(sign>0 && a.at(0)<=0){
    ans += -a.at(0)+1;
    a.at(0) += -a.at(0)+1;
  }
  if(sign<0 && a.at(0)>=0){
    ans += a.at(0)+1;
    a.at(0) -= a.at(0)+1;
  }
  long long sum = a.at(0);
  for(int i=1; i<a.size(); i++){
    if(sum>0 && a.at(i)+sum>=0){
      ans += a.at(i)+sum+1;
      a.at(i) -= a.at(i)+sum+1;
    }
    if(sum<0 && a.at(i)+sum<=0){
      ans += -(a.at(i)+sum-1);
      a.at(i) += -(a.at(i)+sum-1);
    }
    sum += a.at(i);
  }
  return ans;
}
    
int main(){
 int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a.at(i);
  }
  cout << min(f(a,1),f(a,-1));
}