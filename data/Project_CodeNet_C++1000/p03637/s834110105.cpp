#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    double cnt=0;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
        if (a[i]%4==0) cnt++;
        else if (a[i]%2==0) cnt+=0.5;
    }
    if (N/2<=cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
}