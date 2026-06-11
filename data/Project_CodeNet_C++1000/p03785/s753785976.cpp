#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, c, k;
    cin >> n >> c >> k;

    vector<long long> T;

    long long t;
    for(long long i = 0; i < n; i++){
        cin >> t;
        T.push_back(t);
    }

    sort(T.begin(), T.end());

    long long left = 0;
    long long right = 0;
    
    long long count = 0;
    long long sum = 0;

    for(long long i = 0; i < n; i++){
        if(T[i] > right){
            left = T[i];
            right = T[i] + k;
            count = 1;
            sum++;
        }

        if(count > c) {
            left = T[i];
            right = T[i] + k;
            count = 1;
            sum++;
        }

        count++;
    }

    printf("%lld\n", sum);

    return 0;
}