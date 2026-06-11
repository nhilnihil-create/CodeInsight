#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;

    vector<int>vec(b);
    for(int i=1; i<=b; i++){
        int m = a%b;
        m *= i;
        m %= b;
        vec[i-1] = m;
    }
    bool f = 0;
    for(int i=0; i<b; i++){
        if(vec[i]==c) f = 1;
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}