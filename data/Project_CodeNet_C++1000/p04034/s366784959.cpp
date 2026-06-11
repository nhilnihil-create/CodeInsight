#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
  if(a%b==0) return b;
  return gcd(b, a%b);
}

int main(){
  int n, m;  cin >> n >> m;
  vector<ll> box(n, 1);
  set<int> place = {0};

  for(int i=0; i<m; i++){
    int x, y;  cin >> x >> y;
    x--; y--;
    box[x] -= 1;
    box[y] += 1;
    if(place.find(x)!=place.end()){
      place.insert(y);
      if(box[x]==0) place.erase(x);
    }
  }
  cout << place.size() << endl;
  
}
