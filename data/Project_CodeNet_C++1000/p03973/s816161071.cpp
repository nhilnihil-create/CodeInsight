#include <vector>
#include <iostream>
using namespace std;
using ll = long long int;
 
int main(){
    int n; cin >> n;
    int current = 0;
    ll ans = 0;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if(i == 0){
            current++;
            if(a > 1){
                ans += a-1;
            }
            continue;
        }
        else if(a == current + 1){
            current++;
            continue;
        }
        if(a % (current + 1) == 0){
            ans += (a - 2) / (current + 1);
        }
        else{
            ans += (a - 1) / (current + 1);
        }
    }
    cout << ans << endl;
    return 0;
}