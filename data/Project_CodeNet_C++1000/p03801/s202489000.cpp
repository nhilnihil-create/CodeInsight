#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  vector<LL> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<int> b(n,0);
  b[0]=0;
  int now=1;
  for(int i=1;i<n;i++){
    if(a[i]>a[b[now-1]]){
      b[now]=i;
      now++;
    }
  }
  // for(int i=0;i<now;i++) cout << b[i] << endl;
  priority_queue<LL> q;
  vector<LL> ans(n,0);
  LL total=0,num=0,prenum=0;
  if(now==1){
    for(int i=0;i<n;i++){
      ans[0]+=a[i];
    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;
  }else{
    for(int i=b[now-1];i<n;i++){
      q.push(a[i]);
    }
    for(int i=now-1;i>0;i--){
      // cout << i << "---------" << endl;
      total=0;
      while(!q.empty()&&q.top()>a[b[i-1]]){
        // cout << q.top() << " ";
        total+=q.top()-a[b[i-1]];
        num++;
        q.pop();
      }
      // cout << endl;
      // cout << endl;
      total+=prenum*(a[b[i]]-a[b[i-1]]);
      // cout << prenum << endl;
      prenum=num;
      ans[b[i]]=total;
      // if(i>1){
        for(int j=b[i-1];j<b[i];j++){
          q.push(a[j]);
        }
      // }
    }
    for(int i=0;i<n;i++){
      if(a[b[0]]<a[i]) ans[0]+=a[b[0]];
      else ans[0]+=a[i];
    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;
  }
  return 0;
}
