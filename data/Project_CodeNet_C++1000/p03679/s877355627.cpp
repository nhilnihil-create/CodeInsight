#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int x, a, b;
    cin >> x >> a >> b;
    if((b-a) > x)
    {
        cout << "dangerous";
    }
    else if((b-a) <= x && (b-a) > 0)
    {
        cout << "safe";
    }
    else
    {
        cout << "delicious";
    }
    
    cout << endl;
}
