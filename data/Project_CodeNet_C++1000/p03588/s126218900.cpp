#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100002], b[100002];
    int les = 1000000002, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if(b[i] < les){
            les = b[i];
            ans = b[i] + a[i];
        }
    }
    cout << ans << endl;
}