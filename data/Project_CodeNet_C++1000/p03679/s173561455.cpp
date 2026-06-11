#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main() {
int x,a,b;
cin >> x >>a >>b;
if(a>=b) {cout <<"delicious" << endl;
return 0;}

if(b-a<=x) {
    cout << "safe" <<endl;
    return 0;
}
else cout << "dangerous" <<endl;
} 