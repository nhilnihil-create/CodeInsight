#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b;
    string ans = "Impossible";
    cin >> a >> b;
    if(a%3==0 || b%3==0 || (a+b)%3==0) ans = "Possible";
    cout << ans << endl;

}
