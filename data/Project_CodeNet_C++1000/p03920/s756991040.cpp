#include <iostream>

using namespace std;

int main(){
    int n, i;
    cin >> n;

    i = 1;
    while((i + 1) * i < n * 2){
        i++;
    }

    while(n > 0){
        if(n - i >= 0){
            cout << i << '\n';
            n -= i;
        }
        i--;
    }
}