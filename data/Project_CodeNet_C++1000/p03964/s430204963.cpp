#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    long long int curt=1, cura=1;
    for(int n=0; n<N; n++) {
        long long int T, A;
        cin >> T >> A;
        long long int kt=curt/T;
        long long int ka=cura/A;
        if(curt%T!=0) {
            kt++;
        }
        if(cura%A!=0) {
            ka++;
        }
        curt = max(kt, ka)*T;
        cura = max(kt, ka)*A;
    }
    cout << curt + cura << endl;


    return 0;
    
}