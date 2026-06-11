#include<bits/stdc++.h>
using namespace std;
template<class T>void chmax(T& x, T y){if(x < y) x = y;}
int N;
vector<int> as;
int cnt[100];
bool flag = true;

int main(){
    cin >> N;
    int mx = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        cnt[a]++;
        chmax(mx, a);
    }

    for(int i = mx; i > (mx + 1) / 2; i--){
        if(cnt[i] < 2) flag = false;
    }
    for(int i = 0; i < (mx + 1) / 2; i++){
        if(cnt[i] > 0) flag = false;
    }
    if(mx % 2 == 0){
        if(cnt[mx / 2] != 1) flag = false;
    }else{
        if(cnt[(mx + 1) / 2] != 2) flag = false;
    }
    cout << (flag ? "Possible" : "Impossible")  << endl;
    return 0;
}