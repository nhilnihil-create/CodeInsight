#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1e5 + 5;
lint N, A, B, H[MAX_N];

int main(){
    cin >> N >> A >> B;
    for(int i=0;i<N;i++) cin >> H[i];

    lint left = -1, right = 2e9, d = A - B;
    while(1<right-left){
        lint mid = (left+right) / 2, cnt = 0;
        for(int i=0;i<N;i++){
            if(mid*B<H[i]) cnt += (H[i]-mid*B+d-1) / d;
        }
        if(cnt>mid) left = mid;
        else right = mid;
    }

    cout << right << endl;
    return 0;
}