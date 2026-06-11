# include <iostream>
using namespace std;

int main(){
    int N, K, X, Y;
    int sum;

    cin >> N >> K >> X >> Y;

    if (N <= K){
        sum = N*X; 
    }
    else {
        sum = N * X - (X - Y) * (N - K);
    }

    cout << sum << endl;
}