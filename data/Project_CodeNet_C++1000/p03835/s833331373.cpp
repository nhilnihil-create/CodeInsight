#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    // Your code here!
    ll K,S,ans=0;
    cin >>K>>S;
    for(int X =0; X <= K; X++){
        for(int Y=0; Y <= K; Y++){
            int Z =S-X-Y;
            if(0<=Z && Z<=K){
                ans++;
                
            }
        }
    }
    cout << ans << endl;
}
