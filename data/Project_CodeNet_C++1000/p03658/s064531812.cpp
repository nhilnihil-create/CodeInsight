#include <iostream>
#include <string>
#include <algorithm>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <math.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int lA[N+10];
    for (int i=0; i<N; i++) cin >> lA[i];
    sort(lA, lA + N, greater<int>());
    int sum = 0;
    for (int i=0; i<K; i++) sum+=lA[i];
    cout << sum << endl;

}