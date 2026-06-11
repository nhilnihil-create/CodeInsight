#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==1){
            cout << 1 << endl;
        }else{
            int total=0;
            for(int i=n;i>=1;i--){
                total+=i;
            }cout << total << endl;
        }
    }
}