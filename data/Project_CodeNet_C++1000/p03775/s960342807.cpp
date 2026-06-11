#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    long long n; cin >> n;
    int b,digit;
    int minf=11;
    for (int i = 1; i <= (int)sqrt(n); i++)
    {
        if(n%i==0) {
            b = n/i;
            digit=0;
            while(b){
                digit++;
                b /= 10;
            };
            if(minf>digit) minf = digit;
        }
    }
    
    cout << minf << endl;
    
    
    return 0;
}