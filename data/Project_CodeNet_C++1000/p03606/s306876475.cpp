#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,pep;
    cin >> N;

    for(int i = 0; i < N;i++){
        int l,r,cnt;
        cin >> l >> r;
        cnt = r - l + 1;
        pep += cnt;
    }

    cout << pep << endl;
}