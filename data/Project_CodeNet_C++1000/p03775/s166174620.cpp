#include <bits/stdc++.h>
using namespace std;

int main(){
    
    long long int n;
    cin >> n;
    long long int num;

    for(long long int i=sqrt(n); i>0; i--){
        if(n%i==0){
            num=n/i;
            break;
        }
    }
//    cout << num << endl;

    int ans=0;
    while(num>0){
        ans++;
        num/=10;
    }
    cout << ans << endl;
}