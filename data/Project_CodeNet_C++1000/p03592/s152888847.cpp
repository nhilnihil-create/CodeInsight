#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, m, K;
    cin >> n >> m >> K;


    bool flag = false;

    for(long long k = 0; k <= n; k++){
        for(long long l = 0; l <= m; l++){
            if(k*(m-l) + l*(n-k) == K){
                flag = true;
                break;
            }
        }
    }
    if(flag == true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}