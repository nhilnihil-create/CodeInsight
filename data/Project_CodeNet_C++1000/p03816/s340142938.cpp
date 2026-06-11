#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>num(100001);
  set<int>two;
  int i;
  for(i=0;i<n;i++){
    cin >> a[i];
    num[a[i]]++;
  }
  int cnt = n;
  for(i=1;i<=100000;i++){
    while(num[i]>=3){
      num[i]-=2;
      cnt -= 2;
    }
    if(num[i]==2)two.insert(i);
  }
  cnt -= two.size();
  if(two.size()%2==1)cnt--;
  cout << cnt << endl;


}
