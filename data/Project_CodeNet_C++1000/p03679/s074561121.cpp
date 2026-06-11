#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(c-b  <= 0){
        cout << "delicious" << endl;
    }
    else if(c-b > 0 && c-b <= a){
        cout << "safe" << endl;
    }
    else{
        cout << "dangerous" << endl;
    }
}
