#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long int> A(3);
    bool flag=false;
    for(int i=0; i<3; i++) {
        cin >> A[i];
        if(A[i]%2==0) {
            flag=true;
        }
    }
    if(flag) {
        cout << 0 << endl;
    } else {
        sort(A.begin(), A.end());
        cout << A[0]*A[1] << endl;
    }



    return 0;
    
}