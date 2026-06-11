#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n, l, r = 0;
    cin >> n >> l;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        if(a[i]+a[i-1] >= l) {
            r = i;
            break;
        }
    }
    if(r >= 1){
        puts("Possible");
        for(int i=1;i<r;i++) cout << i << endl;
        for(int i=n-1;i>=r;i--) cout << i << endl;
    }else{
        puts("Impossible");
    }
}
