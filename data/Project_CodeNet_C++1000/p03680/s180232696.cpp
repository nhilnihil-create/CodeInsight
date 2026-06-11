#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> frag(N, 0);

    rep2(i, 0, N){
        cin >> a.at(i);
    }

    int index = 0, num = 0;

    while(index != 1 && frag.at(index) != 1){
        frag.at(index) = 1;
        index = a.at(index) - 1;
        num++;
    }

    if(index == 1) cout << num << endl;

    if(frag.at(index) == 1) cout << -1 << endl;
}
