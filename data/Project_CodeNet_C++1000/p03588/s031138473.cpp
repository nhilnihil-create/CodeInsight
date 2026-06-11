#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    long long g,a,b,sb=9999999999;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
            if (sb > b) {
                sb = b;
                g = a+b;
            }
    }
    cout << g << endl;
    return 0;
}