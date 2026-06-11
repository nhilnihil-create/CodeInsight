#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << min(a+b, min(b+c, c+a)) << endl;
}




