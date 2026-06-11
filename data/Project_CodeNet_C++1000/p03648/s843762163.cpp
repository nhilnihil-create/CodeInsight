#include <iostream>

using namespace std;

int main(){
    long K;
    long a[50];
    cin >> K;
    
    cout << 50 << endl;
    for(int i = 0; i < 50; i++){
        if(i >= 50 - K%50) a[i] = i+1;
        else a[i] = i;
        a[i] += K/50;
        cout << a[i] << ' ';
    }
    cout << endl;
}