//n奇数：奇数回目：前、偶数回目：後ろ
//n偶数：奇数回目：後ろ、偶数回目：前
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  deque<int> que;
  if(n%2!=0){
    rep(i, n){
      int num;
      cin >> num;
      if(i%2==0){
        que.push_front(num);
      }else{
        que.push_back(num);
      }
    }
  }else{
    rep(i, n){
      int num;
      cin >> num;
      if(i%2==0){
        que.push_back(num);
      }else{
        que.push_front(num);
      }
    }
  }
  for(auto p : que){
    cout << p << " ";
  }
  return 0;
}