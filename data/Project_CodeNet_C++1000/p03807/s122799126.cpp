#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    int odd_cnt = 0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(a%2 != 0) odd_cnt++;
    }

    if(odd_cnt%2 == 0)  cout << "YES" << endl;
    else cout <<"NO" << endl;

}