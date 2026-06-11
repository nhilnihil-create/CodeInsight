#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int W, a, b;
    cin >> W >> a >> b;
    if(a+W < b) {
        cout << b - (a+W) << endl;
        return 0;
    }
    else if(b+W < a){
        cout << a - (b+W);
    }
    else {
        cout << '0' << endl;
        return 0;
    }
    return 0;
}