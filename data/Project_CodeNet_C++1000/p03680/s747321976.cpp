#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  queue<int> btn;
  btn.push(a[0]);
  int cnt=0;
  bool flag=0;
  rep(i,n){
    cnt++;
    if(btn.front()==1){
      flag=1;
      break;
    }
    btn.push(a[btn.front()]);
    btn.pop();
  }
  if(flag) cout<<cnt<<endl;
  else cout<<-1<<endl;
}