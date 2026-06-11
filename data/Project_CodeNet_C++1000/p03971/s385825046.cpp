#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, allCnt = 0, overseaCnt = 0;
    string students;
    cin >> n >> a >> b;
    cin >> students;
    for (int i = 0; i < n; i++){
        if (students[i] == 'a'){
            if (allCnt < a + b){
                allCnt++;
                cout << "Yes" << "\n";
                continue;
            }
        }
        if (students[i] == 'b'){
            if (allCnt < a + b && overseaCnt < b){
                allCnt++;
                overseaCnt++;
                cout << "Yes" << "\n";
                continue;
            }
        }
        cout << "No" << "\n";
    }

    return 0;
}
