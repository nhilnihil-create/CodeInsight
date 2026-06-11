#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (min(b,d) -max(a,c) <= 0) cout << 0 << endl;
    else cout << min(b,d)-max(a,c) << endl;
    
    
    return 0;    
}