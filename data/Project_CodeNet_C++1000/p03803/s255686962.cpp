#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    if(a == 1 && b != 1){
        cout << "Alice";
    }
    else if(b == 1 && a != 1){
        cout << "Bob";
    }
    else if(b > a){
        cout << "Bob";
    }
    else if(b < a){
        cout << "Alice";
    }
    else{
        cout << "Draw";
    }
    cout << endl;
}