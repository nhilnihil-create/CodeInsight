#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    
    vector<long long int> hen;
    
    long long int x;
    for (int i = 0; i < 3; i++) {
        cin >> x;
        if (x % 2 == 0) {
            cout << "0" << endl;
            return 0;
        }
        hen.push_back(x);
    }
    
    sort(hen.begin(), hen.end());
    cout << hen.at(0) * hen.at(1) << endl;
    
    return 0;
}