#include <iostream>
using namespace std;
int main(){
    int N, l, r, count = 0;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> l >> r;
        count = count + r - l + 1;
    }
    
    cout << count << endl;
}
