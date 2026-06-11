#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[103];
    int d[103] {0};
    int lar = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        lar = max(lar, a[i]);
        d[a[i]]++;
    }
    for(int i = 0; i <= lar; i++){
        int k = max(i, lar - i);
        if(d[k] <= 0){
            cout << "Impossible" << endl;
            return 0;
        }
        d[k]--;
    }
    for(int i = 0; i < n; i++){
        if(d[i] != 0 && (i > lar || i <= (lar + 1) / 2)){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}