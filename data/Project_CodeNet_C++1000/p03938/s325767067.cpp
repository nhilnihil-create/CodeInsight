#include <iostream>
using namespace std;
int main(void){
    int n, a[20000];
    cin >> n;
    for(int i=0;i<n;i++){
        a[i] = 50000 * i + 1;
    }
    for(int i=0;i<n;i++){
        int p;
        cin >> p;
        a[p-1] += i+1;
    }
    
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << 50000 * (n-1-i) + 1 << " ";
    }
    cout << endl;
}
