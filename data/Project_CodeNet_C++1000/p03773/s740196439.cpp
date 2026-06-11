#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    int time = a+b;
    if(time >= 24){
        cout << time - 24 << endl;
    }
    else{
        cout << time << endl;
    }
}