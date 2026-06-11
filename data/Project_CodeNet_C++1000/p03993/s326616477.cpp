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
        l[i]--;
    }
    long cnt = 0;
    for(int i = 0; i < n; i++){
        if(i == l[l[i]]) cnt++;
    }
    cnt /= 2;
    cout << cnt << endl;
    return 0;
}