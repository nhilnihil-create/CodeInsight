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
    int n;
    cin >> n;
    vector<long> l(3*n);
    for(int i = 0; i < 3 * n;i ++){
        cin >> l[i];
    }
    long sum = 0;
    sort(l.begin(), l.end(), greater<int>());
    for(int i = 0; i < 2*n; i++){
        if(i%2 == 1) sum += l[i];
    }
    
    cout << sum << endl;
    return 0;
}