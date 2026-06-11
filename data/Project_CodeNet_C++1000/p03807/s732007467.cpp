#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long int> vec(2, 0);
    for(int n=0; n<N; n++) {
        long long int A;
        cin >> A;
        vec[A%2]++;
    }
    
    if(vec[1]%2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }


    return 0;
    
}