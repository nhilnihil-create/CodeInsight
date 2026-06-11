#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    if(x == 1 || x == n * 2 - 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int d = 1;
    for(int i = 0; i < n - 2; i++){
        if(d == x - 1) d += 3;
        cout << d << endl;
        d++;
    }
    for(int i = 0; i < 3; i++) cout << x - 1 + i << endl;
    for(int i = 0; i < n - 2; i++){
        if(d == x - 1) d += 3;
        cout << d << endl;
        d++;
    }
}
