#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
  int N,i;
  ll f=0, l=0;
  cin >> N;
  vector<int> a(N*3);
  vector<ll> s(N+1,0);
  priority_queue<ll, vector<ll>, greater<ll>> pqf;
  priority_queue<ll> pql;
  
  for(i=0; i<N*3; i++) {
    cin >> a.at(i);
    if(i<N) {
      pqf.push(a.at(i));
      f += a.at(i);
    }
    if(i>=N*2) {
      pql.push(a.at(i));
      l += a.at(i);
    }
  }
  
  for(i=N; i<=N*2; i++) {
    s.at(i-N) +=  f;
    s.at(N*2-i) -= l;
    pqf.push(a.at(i));
    f += a.at(i)-pqf.top();
    pqf.pop();
    pql.push(a.at(N*3-i-1));
    l += a.at(N*3-i-1)-pql.top();
    pql.pop();
  }

  cout << *max_element(s.begin(), s.end()) << endl;
}