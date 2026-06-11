#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n;
map<int,int> s;

int main(){
  cin >> n;
  int a = INF;
  rep(i,0,n) {
    int x;
    cin >> x;
    a = min(a,x);
    s[x]++;
  }
  bool t = true;
  if(s.size() > 2)t = false;
  if(s.size() == 2){
    int k = s[a];
    int l = s[a+1];
    if(k>a || l < 2*(a+1-k))t=false;
  }else if(s.size() == 1){
    if(a == n-1)t = true;
    else{
      a--;
      int k = 0;
      int l = n;
      if(k>a || l < 2*(a+1-k))t=false;
    }
  }
  cout << (t?"Yes":"No") << endl;

  return 0;
}
