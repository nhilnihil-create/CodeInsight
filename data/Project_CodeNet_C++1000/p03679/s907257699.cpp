#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
  
int main(void){
    int x, a, b;
    cin >> x >> a >> b;
    
    if(b-a <= 0){
        cout << "delicious";
        return 0;
    } else if ((0 < (b-a)) && ((b-a) <= x)) {
        cout << "safe";
        return 0;
    } else {
        cout << "dangerous";
    }
    
    return 0;
}