#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    long long int Q, H, S, D, N, p, P1, P2;
    cin >> Q >> H >> S >> D >> N;
   
    p = min(min(Q * 4, H * 2), S);

    P1 = N * p;
    P2 = N / 2 * D + N % 2 * p;

    cout << min(P1, P2);

    return 0;

}

