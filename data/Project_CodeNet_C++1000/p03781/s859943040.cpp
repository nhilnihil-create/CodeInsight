#include <iostream>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    for(long long int i=0; ; i++){
        if(i*(i+1) >= 2*n){
            cout << i << endl;
            break;
        }
    }
    return 0;
}
