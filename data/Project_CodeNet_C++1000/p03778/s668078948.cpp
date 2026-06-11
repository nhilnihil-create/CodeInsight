#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
int w,a,b,y;
cin >> w >> a >> b;
if(b>=a && b <= a+w) y = 0;
else if(a<b){
  y =  abs(b - a - w);
}
else{
  y = abs(a-b-w);
}

cout << y << endl;
}
