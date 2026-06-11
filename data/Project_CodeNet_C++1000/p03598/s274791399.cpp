#include <iostream>
using namespace std;
int main(void){
    int N;
    int K;
    int A=0;
    cin >> N >> K;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        if (x * x <= (K - x) * (K - x)){
            A = A + 2*x;
        }
        else if (x * x > (K-x)*(K-x)){
            A = A + 2*(K-x);
        }
    }
    cout << A << endl;
}