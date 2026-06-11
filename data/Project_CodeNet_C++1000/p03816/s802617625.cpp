#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
const int max_n = 1e5;
const ll mod = 1e9+7;
void send(int a,int b,int c,int d){
  printf("%d %d %d %d\n",a,b,c,d);
}
int main(){
  int n;  cin >> n;
  map<int,int> ma;
  rep(i,0,n){
    int x;  cin >> x;
    ma[x]++;
  }
  priority_queue<int> que;
  for(auto ite=begin(ma) ; ite!=end(ma) ; ite++){
    que.push(ite->se);
  }
  while(que.size()>1){
    if(que.top()==1) break;
    int x=que.top();  que.pop();
    int y=que.top();  que.pop();
    if(x-1>0) que.push(x-1);
    if(y-1>0) que.push(y-1);
  }
  int ans = que.size();
  cout << ans << endl;
  return 0;
}
