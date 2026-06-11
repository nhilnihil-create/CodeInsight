#include <bits/stdc++.h>
using namespace std;

void fail(){
    cout << "Impossible" << endl;
    exit(0);
}

int main(){
    int N;
    cin >> N;
    int num[101] = {0};
    int mx = 0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        mx = max(mx, a);
        num[a]++;
    }
    if(num[mx] < 2) fail();
    int mn = N;
    for(int i=0; i<=mx; i++){
        int a = max(i, mx-i);
        mn = min(mn, a);
        if(num[a] == 0) fail();
        num[a]--;
    }
    for(int i=1; i<=mn; i++) if(num[i] > 0) fail();
    cout << "Possible" << endl;
}