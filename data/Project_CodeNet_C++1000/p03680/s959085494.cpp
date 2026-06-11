#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i=0; i<N; i++) {
        cin >> a.at(i);
    }

    int count=0;
    int j = 0;

    for(int i=0; i<N; i++) {
        count++;
        if(a.at(j)==2) {
            break;
        }
        j=a.at(j)-1;
    }
    if(count<N) {
        cout << count << endl;
    }
    else {
        cout << -1 << endl;
    }
}