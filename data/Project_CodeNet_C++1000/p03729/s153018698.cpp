#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string a, b, c, ans="NO";
    cin >> a >> b >> c;
    if(a[a.size()-1]==b[0] && b[b.size()-1]==c[0]) ans = "YES";
    cout << ans << endl;

}