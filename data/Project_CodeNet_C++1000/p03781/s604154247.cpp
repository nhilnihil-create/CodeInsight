#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define inf 1000000007

int main(void){
    int x;
    cin >> x;
    int ans = 0;
    int max = 1000000000;
    int i = 1;
    for(int i = 0; i < max; i++){
        ans+=i;
        if(ans>=x){
            cout << i << endl;
            break;
        }
    }
    return 0;
}