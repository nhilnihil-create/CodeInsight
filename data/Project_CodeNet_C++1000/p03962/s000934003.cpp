#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  set<int> p;
  p.insert(a);
  p.insert(b);
  p.insert(c);
  cout << p.size() << endl;
}