#include<iostream>

using namespace std;

int main()
{
    long long k;
    cin >> k;
    long long a[51];
    for(int i = 1; i <= 50; i++){
        a[i] = 49 + (k / 50) - (k % 50);
    }
    for(int i = 1; i <= (k % 50); i++){
        a[i] += 50 + 1;
    }
    cout << 50 << endl;
    for(int i = 1; i <= 49; i++){
        cout << a[i] << " ";
    }
    cout << a[50] << endl;
    return 0;
}