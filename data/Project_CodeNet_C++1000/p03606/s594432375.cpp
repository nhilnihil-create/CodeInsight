#include <iostream>
using namespace std;

int main() {
    int N;
    int start, goal;
    int sum = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> start >> goal;
        sum += goal - start + 1;
    }
    cout << sum << endl;

}