#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
using namespace std;
int main(){
    int N,K,i,p,a;
    cin >> N >> K;
    int l[N] = {};
    for(i = 0;i < N;i++){
        cin >> p;
        l[i] = p;
    }
    sort(l, l + N, greater<int>());
    a = 0;
    for(i = 0;i < K;i++){
        a += l[i];
    }
    cout << a << endl;
}