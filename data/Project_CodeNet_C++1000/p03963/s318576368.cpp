#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;
    
    cout << int(K * pow(K-1, N-1)) << endl;
    return 0;
}