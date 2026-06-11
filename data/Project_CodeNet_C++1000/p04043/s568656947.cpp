#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int     tmp;
    int     cnt_5 = 0, cnt_7 = 0;
    
    for ( int ii = 0; ii < 3; ii++ ) {
        scanf("%d", &tmp);
        if ( tmp == 5 ) {
            cnt_5++;
        } else if ( tmp == 7 ) {
            cnt_7++;
        }
    }
    
    if ( cnt_5 == 2 && cnt_7 == 1 ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}