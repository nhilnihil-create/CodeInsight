#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
using namespace std;
int main(){
    int K,S,i,j,a;
    cin >> K >> S;
    a = 0;
    for(i = 0;i <= K;i++){
        for(j = 0;j <= K;j++){
            if(S - i - j <= K && S - i - j >= 0){
                a++;
            }
        }
    }
    cout << a << endl;
}