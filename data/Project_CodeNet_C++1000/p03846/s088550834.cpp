#include <iostream>
#define MOD 1000000000+7
using namespace std;

int main(void){
    int n;
    cin>>n;
    int a_count[n] = {};
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        a_count[a] ++;
    }
    long long ans=1;
    for(int i= (n%2)+1;i<n;i+=2){
        if(a_count[i] == 2){
            ans *= 2;
            ans %= MOD;
        }else{
            ans = 0;
            break;
        }
    }
    if(n%2 == 1 && a_count[0] !=1) ans =0;
    
    cout<<ans<<endl;
}