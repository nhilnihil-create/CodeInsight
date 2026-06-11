#include <bits/stdc++.h>
using namespace std;
int main(){


int x,y,a,b;
 cin >> x >> y >> a >> b;
 string ans = string(b-y,'U')+string(a-x,'R')+string(b-y,'D')+string(a-x,'L');
 ans += string(1,'L')+string(b-y+1,'U')+string(a-x+1,'R')+string(1,'D');
 ans += string(1,'R')+string(b-y+1,'D')+string(a-x+1,'L')+string(1,'U');
 cout << ans;

}