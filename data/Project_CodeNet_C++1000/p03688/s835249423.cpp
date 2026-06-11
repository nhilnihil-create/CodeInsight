#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100002];
    int les = n;
    int lar = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        les = min(les, a[i]);
        lar = max(lar, a[i]);
    }
    if(lar - les > 1){
        cout << "No" << endl;
        return 0;
    }
    if(lar == les && lar == n - 1){
        cout << "Yes" << endl;
        return 0;
    }
    int col = lar;
    int rest = n;
    if(lar - les == 1){
        for(int i = 0; i < n; i++) 
            if(a[i] == les){
                col--;
                rest--;
            }
    }
    if(col > 0 && rest / col >= 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}