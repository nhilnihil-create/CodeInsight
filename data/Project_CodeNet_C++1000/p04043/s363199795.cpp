#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int cnt_5 = 0, cnt_7 = 0;
    
    if(A == 5) cnt_5++;
    else if(A == 7) cnt_7++;

    if(B == 5) cnt_5++;
    else if(B == 7) cnt_7++;

    if(C == 5) cnt_5++;
    else if(C == 7) cnt_7++;

    if(cnt_5 == 2 && cnt_7 == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
