#include <iostream>
#include <algorithm>
using namespace std;
int main(void){

    int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++) cin >> a[i];
    
    int k = 1;
    int count = 0;
    bool can = false;
    for(int i=1;i<=N;i++){
        count++;
        if(a[k-1]==2) {
            can = true;
            break;
        }
        k = a[k-1];
    }
    
    if(can)cout << count;
    if(!can) cout << "-1";
}