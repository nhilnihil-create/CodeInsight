#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 100000

typedef long long ll;
typedef pair<ll,ll> P;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

int main(){
    int N;
    cin >> N;
    int count = 0;
    for(int i = 0;  i < N; i++){
        int l,r;
        cin >> l >> r;
        count += r - l + 1;
    }
    cout << count << endl;
    return 0;
}
