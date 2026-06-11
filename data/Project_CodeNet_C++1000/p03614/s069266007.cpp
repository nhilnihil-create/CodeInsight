#include <iostream>
using namespace std;
int main(void){
    int n, q, ans = 0;
    cin >> n >> q;
    for(int i=1;i<=n-1;i++){
        int p;
        cin >> p;
        if(q == i || (i == n-1 && p == i+1)){
            ans++;
        }else{
            q = p;
        }
    }
    
    cout << ans << endl;
}
