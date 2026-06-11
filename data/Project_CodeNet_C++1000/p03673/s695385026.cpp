#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main() {
  int n;
  cin>>n;
  deque<int>q;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(i%2==0){
      q.push_back(a);
    }else{
      q.push_front(a);
    }
  }
  if(n%2==1)reverse(q.begin(),q.end());
  for(int i=0;i<n;i++){
    if(i==n-1)cout<<q[i]<<endl;
    else cout<<q[i]<<" ";
  }
  return 0;
}
