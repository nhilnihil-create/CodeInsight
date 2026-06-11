#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  cout << (multiset<int>({a,b,c}) == multiset<int>({5,7,5})?"YES":"NO") << endl;
}