#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    long long N, M;
    cin >> N >> M;
    long long rN, rM;
    long long make = 0;
    if(N*2 <= M){
        make += N;
        rM = M - N*2;
        rN = 0;
    }
    else if(N*2 > M){
        make += M / 2;
        cout << make << endl;
        return 0;
    }
    make += rM / 4;
    cout << make << endl;
    return 0;
}