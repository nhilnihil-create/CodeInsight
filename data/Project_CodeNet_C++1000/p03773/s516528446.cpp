#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, ans;
    cin >> a >> b;
    ans = a+b;
    if(24<=ans) ans -= 24;
    cout << ans << endl;
}