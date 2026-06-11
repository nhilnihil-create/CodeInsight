#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A,A+N);
    int ans = 0;
    int num = -1;
    for(int i=0;i<N;i++){
        if(num != A[i]){
            ans++;
            num = A[i];
        }
    }
    if(ans % 2 == 0){
        ans--;
    }
    cout << ans << endl;
}
