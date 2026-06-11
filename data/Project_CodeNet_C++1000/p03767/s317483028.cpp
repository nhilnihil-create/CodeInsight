#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a;

    long long x;
    for(long long i = 0; i < 3*n; i++){
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    long long sum = 0;
    long long j = 3*n-2;
    long long i = 0;
    while(i < n){
        sum += a[j];
        //cout << a[j] << endl;
        //cout << "j" << j << endl;
        j = j - 2;
        i++;
    }

   cout << sum << endl;

    return 0;
}