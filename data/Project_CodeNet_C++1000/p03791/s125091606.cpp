#include <iostream>
using namespace std;

using ll = long long;

ll a[100010];

int main(void){
    // Here your code !
    
    ll n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    ll res = 1,dassyutu = 0;
    
    for(int i = 0; i < n; i++){
        
        //cout << res << " " << a[i] << " " << 2*(i-dassyutu)+1 << endl;
        
        if(a[i] >= 2*(i-dassyutu)+1){
            
        }else{
            res *= i-dassyutu+1;
            dassyutu++;
            res %= 1000000007;
        }
        
    }
    
    //cout << res << endl;

    for(int i = 1; i <= n-dassyutu; i++){
        res *= i;
        res %= 1000000007;
    }
    
    cout << res << endl;
    
}
