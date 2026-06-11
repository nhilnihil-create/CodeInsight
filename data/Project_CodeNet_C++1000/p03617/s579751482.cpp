#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long int Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    
    H = min(H,Q*2);
    S = min(S,H*2);
    
    if (S * 2 <= D)
        cout << N * S << endl;
    else
        cout << (N / 2) * D + (N % 2) * S << endl;

    return 0;
}