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
    long n, cnt = 1;
    cin >> n;
    vector<long> l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    long up = 0;
    for(int i = 1; i < n; i++){
        if(l[i-1] > l[i]){
            if(up == 0) up = -1;
            if(up == 1){
                cnt++;
                up = 0;
            }
        }
        else if(l[i-1] < l[i]){
            if(up == 0) up = 1;
            if(up == -1){
                cnt++;
                up = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}