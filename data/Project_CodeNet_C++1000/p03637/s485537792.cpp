#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

int main(){
    int N;
    cin >> N;
    int count4 = 0;
    int counteven = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        if(a % 4 == 0) count4++;
        else if(a % 2 == 0){
            counteven++;
        } 
    }
    int zan = N - count4 - counteven;
    if(counteven == 0 && 2 * count4 + 1 >= N) cout << "Yes" << endl; 
    else if(zan <= count4) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
