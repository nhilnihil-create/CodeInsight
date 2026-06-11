#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int w,a,b;
    cin >> w >> a >> b;
    if(abs(a-b)<=w) cout << 0 << endl;
    else{

    cout << min(abs(a+w-b),abs(b+w-a))  << endl;    }

}