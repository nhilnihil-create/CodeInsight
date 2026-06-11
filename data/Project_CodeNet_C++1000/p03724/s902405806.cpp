#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N+1, 0);
    for(int m=0; m<M; m++) {
        int a, b;
        cin >> a >> b;
        vec[a]++;
        vec[b]++;
    }
    
    for(int n=1; n<=N; n++) {
        if(vec[n]%2!=0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;



    return 0;
    
}