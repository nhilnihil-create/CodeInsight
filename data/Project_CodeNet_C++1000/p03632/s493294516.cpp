#include <bits/stdc++.h>
using namespace std;

int ans[26];
int main() {
int a,b,c,d;
cin >>a >>b>>c >> d;

int start = max(a,c);
int end = min(b,d);

if(start < end){
  cout << end-start <<endl;
}
else{
  cout << 0 <<endl;
}
}