#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[20003];
    int nth[20003];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        nth[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) cout << 20000 * i + (nth[i] - 10000) << " ";
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << 20000 * (n - i) << " ";
    }
    cout << endl;
}