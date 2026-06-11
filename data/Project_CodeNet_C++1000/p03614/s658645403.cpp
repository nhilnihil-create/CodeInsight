#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int n=0; n<N; n++) {
        int p;
        cin >> p;
        if(p==n+1) {
            vec[n]=1;
        } else {
            vec[n]=0;
        }
    }
    
    int ans=0;
    for(int n=0; n<N; n++) {
        if(vec[n]==1) {
            ans++;
            if(n+1<N && vec[n+1]==1) {
                n++;
            }
        }
    }
    cout << ans << endl;

    return 0;
    
}