#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    vector<int> which {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
    int a, b;
    cin >> a >> b;
    if(which[a] == which[b]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
