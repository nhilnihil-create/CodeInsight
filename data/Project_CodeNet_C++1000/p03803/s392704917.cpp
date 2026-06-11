#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    vector<int> v {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1};
    int a, b;
    cin >> a >> b;
    if(find(v.begin(), v.end(), a) < find(v.begin(), v.end(), b)){
        cout << "Bob";
    }
    else if(find(v.begin(), v.end(), a) > find(v.begin(), v.end(), b)){
        cout << "Alice";
    }
    else
    {
        cout << "Draw";
    }
    
    cout << endl;
}
