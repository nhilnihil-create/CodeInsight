#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(2*N);
    for(int n=0; n<2*N; n++) {
        cin >> vec[n];
    }
    sort(vec.begin(), vec.end());
    int ans=0;
    for(int n=0; n<2*N; n++) {
        ans += vec[n];
        n++;
    }
    cout << ans << endl;


    return 0;
    
}