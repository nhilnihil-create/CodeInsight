#include <bits/stdc++.h>
using namespace std;

int main() {
int x,a,b;
cin >> x >> a >> b;

if(a>=b){
      cout << "delicious"; return 0;
}
if(b-a<=x){
    cout << "safe"; return 0;
}
else{
    cout << "dangerous"; return 0;
}

return 0;
}