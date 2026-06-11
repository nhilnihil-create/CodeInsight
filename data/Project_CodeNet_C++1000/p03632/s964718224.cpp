#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a) < (b)) ? (b) : (a))
#define min(a,b) (((a) > (b)) ? (b) : (a))
int main(void) {
    int A,B,C,D;
    int temp;
    cin >> A >> B >> C >> D;
    temp = min(B,D) - max(A,C);
    if (temp < 0) temp = 0;
    cout << temp << "\n";


    return 0;
}
