#include <iostream>
using namespace std;
int a[1000006], b[1000006];
int main(){
    int n, m, c = 0, l;
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        cin >> a[i];
        if (a[i] % 2){
            l = i;
            ++ c;
        }
    }
    if (n == 1){
        cout << 1 << endl << 1 << endl << 1 << endl;
        return 0;
    }
    if (n % 2 == 1 && c > 1 || n % 2 == 0 && c > 2){
        cout << "Impossible" << endl;
        return 0;
    }
    if (c == 0){
        for (int i = 1; i <= m; ++ i)
            cout << a[i] << " ";
        cout << endl << m + 1 << endl;
        cout << a[1] - 1 << " ";
        for (int i = 2; i <= m; ++i)
            cout << a[i] << " ";
        cout << 1 << endl;
    }
    else if (c == 1){
        cout << a[l] << " ";
        b[1] = a[l];
        for (int i = 1, c = 1; i <= m; ++ i)
            if (a[i] % 2 == 0){
                cout << a[i] << " ";
                b[++ c] = a[i];
            }
        cout << endl << m + (b[1] != 1)<< endl;
        if (b[1] != 1)
            cout << b[1] - 1 << " ";
        for (int i = 2; i <= m; ++ i)
            cout << b[i] << " ";
        cout << 1 << endl;
    }
    else if (c == 2){
        cout << a[l] << " ";
        b[1] = a[l];
        for (int i = 1, c = 1; i <= m; ++ i)
            if (a[i] % 2 == 0){
                cout << a[i] << " ";
                b[++ c] = a[i];
            }
        for (int i = 1; i <= m; ++ i)
            if (a[i] % 2 && i != l){
                cout << a[i] << " ";
                b[m] = a[i];
            }
        cout << endl << m - 1 + (b[1] != 1) + (b[m] != 1) << endl;
        if (b[1] != 1)
            cout << b[1] - 1 << " ";
        cout << 2 << " ";
        for (int i = 2; i < m; ++ i)
            cout << b[i] << " ";
        if (b[m] != 1)
            cout << b[m] - 1 << " ";
        cout << endl;
    }
    return 0;
}
