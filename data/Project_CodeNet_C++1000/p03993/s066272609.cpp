#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n+1);

    long long x;
    for(long long i = 1; i <= n; i++){
        cin >> x;
        a[i] = x;
    }

    long long count = 0;
    for(long long i = 1; i <= n; i++){
        if(a[a[i]] == i){
            count++;
        }
    
    }

    cout << count/2 << endl;

    return 0;
}