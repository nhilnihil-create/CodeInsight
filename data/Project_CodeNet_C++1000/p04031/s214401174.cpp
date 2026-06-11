#include <iostream>
#include <cmath>

int N, total, avg, arr[100];

void solve() {
    std::cin >> N;
    avg = 0;
    total = 0;
    for (int i=0; i<N; ++i) 
        std::cin >> arr[i];
    for (int i=0; i<N; ++i) 
        avg += arr[i];
    avg = round((double)avg/(double)N);
    for (int i=0; i<N; ++i) {
        total += pow((arr[i]-avg), 2);
    }
    
    std::cout << total << std::endl;
}

int main() {
    solve();
    return 0;
}
