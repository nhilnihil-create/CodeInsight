#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

long long PRIME = 1e9 + 7;
using namespace std;

vector<vector<int>> E;


int main(){ 
    int A, B;
    cin >> A >> B;

    A = (A + 12) % 14;
    B = (B + 12) % 14;

    if(A > B){
        cout << "Alice";
    }
    else if(B > A){
        cout << "Bob";
    }
    else{
        cout << "Draw";
    }
}

