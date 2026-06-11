#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int total=k;
    for(int i=1;i<n;i++){
        total*=k-1;
    }cout << total << endl;
}