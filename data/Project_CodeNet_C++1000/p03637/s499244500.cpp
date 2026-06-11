#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
 
#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int tmp;
    int b4,b2,b1 ;
    b4 = 0;
    b2 = 0;
    b1 = 0;
    rep(i,n) {
        cin >> tmp;
        if(tmp%4 == 0){
            b4++;
        }else if(tmp % 2 == 0){
            b2++;
        }else{
            b1++;
        }
    }

    if(b2>0)b1++;
    if(b1 <= b4+1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}