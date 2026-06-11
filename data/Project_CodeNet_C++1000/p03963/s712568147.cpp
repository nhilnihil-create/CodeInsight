#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
using namespace std;
int main(){
    long int N,K,p,i;
    cin >> N >> K;
    p = K;
    K--;
    for(i = 1;i < N;i++){
        p *= K;
    }
    cout << p << endl;
}