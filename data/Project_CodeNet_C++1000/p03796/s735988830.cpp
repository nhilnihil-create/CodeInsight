#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N;
    cin >> N;
    long long power = 1;
    long long c;
    long long d;
    for(int i = 1; i <= N; i++){
        power *= i;   
        power %= 1000000007;
    }
    cout << power  << endl;
    return 0;
}