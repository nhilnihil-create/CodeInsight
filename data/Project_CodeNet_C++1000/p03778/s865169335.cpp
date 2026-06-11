#include <bits/stdc++.h>
using namespace std;
int main(void){
    int W,a,b;
    cin >> W >> a >> b;
    if(min(a,b) + W >= max(a,b)) cout << 0 << endl;
    else cout << max(a,b) - min(a,b) - W << endl;
}
