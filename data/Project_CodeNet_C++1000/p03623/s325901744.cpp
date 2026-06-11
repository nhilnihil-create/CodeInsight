#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int  x, a, b;
    cin >> x >> a >> b;
    int disa = abs(x-a);
    int disb = abs(x-b);
    if(disa > disb){
        cout << "B";
    }
    else{
        cout << "A";
    }   
    cout << endl;
}
