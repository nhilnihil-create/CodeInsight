#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    long long k, t;
    cin >> k >> t;
    vector<long long> v;

    long long maxv = 0;
    for(long long i = 0; i < t; i++){
        long long a;
        cin >> a;
        v.push_back(a);
        if(maxv < a){
            maxv = a;
        }
    }

    cout << max(maxv-1-(k-maxv), (long long)0) << endl;

    return 0;

    
}