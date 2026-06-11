#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long count_live = 1;

    long long sum = a[0];
    for(long long i = 0; i < n-1; i++){
        if(a[i+1] <= 2*sum){
            sum += a[i+1];
            count_live++;
        }
        else{
            count_live = 1;
            sum += a[i+1];

        }
        //printf("sum %lld count_live %lld\n", sum, count_live);
    }

    cout << count_live << endl;
    return 0;
}