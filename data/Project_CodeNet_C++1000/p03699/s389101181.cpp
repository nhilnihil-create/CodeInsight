#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    long n;
    cin >> n;
    vector<long> l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    long sum = accumulate(l.begin(), l.end(), 0L), summ = sum;
    if(sum % 10 == 0){
        for(int i = 0; i < n; i++){
            if(l[i] % 10 == 0) continue;
            else{
                sum -= l[i];
                break;
            }
        }
        if(sum == summ) sum = 0;
    }
    cout << sum << endl;
    return 0;
}
