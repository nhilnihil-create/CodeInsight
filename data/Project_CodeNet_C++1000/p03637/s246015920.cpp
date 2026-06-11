#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    int multiple_two = 0;
    int multiple_four = 0;
    int not_multiple_two = 0;
    for(int i=0; i<N; i++) {
        cin >> a[i];
        if(a[i] % 4 == 0) multiple_four++;
        else if(a[i] % 2 == 0) multiple_two++;
        else not_multiple_two++;
    }

    bool flg = false;
    if(N == multiple_two) flg = true;
    if(multiple_four + 1 >=  not_multiple_two && multiple_two == 0) flg = true;
    if(multiple_four ==  not_multiple_two) flg = true;
    cout << (flg ? "Yes" : "No") << endl;
}