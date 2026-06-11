#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const string YES = "Yes";
const string NO = "No";


int main(){
  ll h, w;
  cin>>h>>w;
  vector<string> v(h);
  for(int i=0; i<h; i++) {
    cin>>v[i];
  }

  map<char, ll> dic;
  for(int i='a'; i<='z'; i++) {
    dic[(char)i]=0;
  }
  for(int i=0; i<h; i++) {
    for(auto x:v[i]) {
      dic[x]++;
    }
  }

  vector<ll> vv;
  for(auto x:dic) {
    vv.push_back(x.second);
  }
  int num=0;
  sort(vv.rbegin(), vv.rend());
  for(auto x:vv) {
    if(x==0)
      break;
    num++;
  }

  for(int i=0; i<(w/2)*(h/2); i++){
    if(vv[0] >= 4) {
      vv[0] -= 4;
      sort(vv.rbegin(), vv.rend());
    } else {
      std::cout << NO << std::endl;
      return 0;
    }
  }

  sort(vv.rbegin(), vv.rend());

  for(int i=0; i<(h-(h/2)*2)*(w/2); i++) {
    if(vv[0] >= 2) {
      vv[0]-=2;
      sort(vv.rbegin(), vv.rend());
    } else {
      std::cout << NO << std::endl;
      return 0;
    }
  }
  sort(vv.rbegin(), vv.rend());
  for(int i=0; i<(w-(w/2)*2)*(h/2); i++) {
    if(vv[0]>=2) {
      vv[0]-=2;
      sort(vv.rbegin(), vv.rend());
    } else {
      std::cout << NO << std::endl;
      return 0;
    }
  }
  std::cout << YES << std::endl;
  return 0;
}
