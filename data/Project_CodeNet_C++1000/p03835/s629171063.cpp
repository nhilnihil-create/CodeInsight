#include <iostream>
using namespace std;
int k, s, cnt = 0;
int main()
{
    cin >> k;
    cin >> s;
    for (int i = 0; i <= k; i++){
        for (int j = 0; j <= k; j++){
            if (((s - i - j) <= k) && (s - i - j) >= 0){
                cnt ++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}