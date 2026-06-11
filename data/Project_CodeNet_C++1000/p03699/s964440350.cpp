#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int res = 0;
    cin >> N;
    vector <int> s(N);
    for (int i=0; i<N; i++) cin >> s.at(i);
    sort(s.begin(), s.end());
    for (int i=0; i<N; i++) res += s.at(i);
    bool isok=false;
    if (res%10==0) {
        for (int i=0; i<N; i++) {
            if (s.at(i)%10!=0) {
                res -= s.at(i);
                isok = true;
                break;
            }
        }
        if (!isok) res = 0;
    }
    cout << res;
}