#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[20005], q[20005];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    int a[20005], b[20005];
    for(int i = 0; i < n; i++){
        a[i] = (i + 1) * 40000;
        b[i] = 1000000000 + q[i] - a[i];
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
}
