#include<bits/stdc++.h>
using namespace std;
/*
alias g='g++ -std=c++17 -O2 pra.cpp'
alias a='./a.out'
cd programming
cd cpp
cd practice

*/
/*
clock_t start = clock();
処理
cout<<"cpu時間: "<<(double)(end-start)/CLOCKS_PER_SEC<<"秒"<< endl;
clock_t end = clock();
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
//if (i) cout << " "; で最初のみ空白文字を出力することができる
#define Sort(v) sort((v).begin(), (v).end())
#define pb push_back
using veci = vector<int>;
using vecs = vector<string>;
using vecd = vector<double>;
using vecl = vector<long long>;
using G = vector<vector<int>>;
using ll = long long;
using P = pair<int, int>;
double PI = acos(-1);
ll lINF = LLONG_MAX; ll lmINF = LLONG_MIN;
int INF = INT_MAX; int mINF = INT_MIN;
struct point{
    double x;
    double y;
};
int main(){
    int k, s; cin >> k >> s;
    int x =0;
    int y = 0;
    int z = 0;
    ll cnt=0;
    for (z=0; z<=k; z++){
        for (y=0; y<=z; y++){
            for (x=0; x<=y; x++){
                if (x + y + z == s){
                    if (x == y && y == z){
                        cnt++;
                    }
                    else if (x != y && y != z && z != x){
                        cnt += 6;

                    }
                    else{
                        cnt += 3;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}