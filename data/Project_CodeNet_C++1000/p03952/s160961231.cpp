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
    if(x <= n){
        for(int i = 1; i <= x - 2; i++) cout << i << " ";
        for(int i = x + 1; i <= n; i++) cout << i << " ";
        cout << x - 1 << " " << x << " ";
        for(int i = n + 1; i <= n * 2 - 1; i++) cout << i << " ";
    }
    else{
        for(int i = 1; i <= n - 1; i++) cout << i << " ";
        cout << x << " " << x + 1 << " ";
        for(int i = n; i <= x - 1; i++) cout << i << " ";
        for(int i = x + 2; i <= n * 2 - 1; i++) cout << i << " ";
    }
    cout << endl;
}