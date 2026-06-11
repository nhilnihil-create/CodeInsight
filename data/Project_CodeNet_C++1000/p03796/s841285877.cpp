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
    long int N,p,i;
    cin >> N;
    p = 1;
    for(i = 1;i <= N;i++){
        p = (p * i) % 1000000007;
    }
    cout << p << endl;
}