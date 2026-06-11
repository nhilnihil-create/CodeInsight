#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, a, b;
    cin >> n >> a >> b;
    
    if(a == b){
        cout << 1 << endl;
        return 0;
    }
    
    cout << max(0LL, (b-a)*1LL*(n-2) + 1) << endl;
    
    
    return 0;
    
}
