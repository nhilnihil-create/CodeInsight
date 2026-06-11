#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    int l[55];
    int ans = 0;
    for (int i=1; i<N+1; i++) cin >> l[i];
    sort(l+1, l+N+1, greater<int>());
    for (int i=1; i<K+1; i++){
        ans += l[i];
    }
    cout << ans << endl;
    return 0;
}
