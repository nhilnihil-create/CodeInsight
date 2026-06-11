#include <iostream>

using namespace std;

int main() {
    long long int N, A, B;
    cin >> N >> A >> B;
    
    long long int ans=A+B*(N-1)-(A*(N-1)+B)+1;
    if(ans<0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }



    return 0;
    
}