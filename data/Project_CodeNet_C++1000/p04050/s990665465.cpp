#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[105];
    if(m == 1){
        if(n == 1){
            cout << 1 << endl;
            cout << 1 << endl;
            cout << 1 << endl;
        }
        else{
            cout << n << endl;
            cout << 2 << endl;
            cout << 1 << " " << n - 1 << endl;
        }
        return 0;
    }
    int c = 0;
    for(int i = 0; i < m; i++){
        cin >> a[i];
        c += a[i] % 2;
    }
    if(c > 2){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = 0; i < m; i++){
        if(a[i] % 2){
            swap(a[i], a[0]);
            break;
        }
    }
    for(int i = m - 1; i >= 0; i--){
        if(a[i] % 2){
            swap(a[i], a[m - 1]);
            break;
        }
    }
    for(int i = 0; i < m; i++) cout << a[i] << " ";
    cout << endl;
    if(a[0] == 1){
        cout << m - 1 << endl;
    }
    else{
        cout << m << endl;
        cout << a[0] - 1 << " ";
    }
    for(int i = 1; i < m - 1; i++) cout << a[i] << " ";
    cout << a[m - 1] + 1 << endl;
}
