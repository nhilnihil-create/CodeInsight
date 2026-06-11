#include<iostream>
using namespace std;

int main(){

    long long n; cin >> n;
    for(long long x = 1; x <= n; x++){

        if((x * (x + 1)) / 2 >= n){
            
            for(long long y = x; y >= 1; y--){
                //cout << y << "" << n << endl;
                if(n >= y){
                    cout << y << endl;
                    n -= y;
                }
            }

            break;
        }
    }

    return 0;
}