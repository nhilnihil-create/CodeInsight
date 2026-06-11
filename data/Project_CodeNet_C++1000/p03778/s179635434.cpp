#include <iostream>

using namespace std;

int main(){
    int W, a, b;
    cin >> W >> a >> b;

    if((b + W) < a){
        cout << abs((b + W) - a) << endl;
    }else if((a + W) < b){
        cout << abs((b - (a + W))) << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}