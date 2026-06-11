#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int>l(N);

    for(int i=0; i<N; i++) cin >> l[i];

    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());

    cout << accumulate(l.begin(), next(l.begin(), K), 0) << endl;



    return 0;
}