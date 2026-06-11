#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[103];
    int b[103]{0};
    int l = n, r = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[a[i]]++;
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    if(l * 2 < r){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = r; i > l; i--){
        if(b[i] < 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if(b[l] - r % 2 != 1){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
}
