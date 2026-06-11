#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int x, y;
    cin >> x >> y;
    if(x == 12 || y == 12)
        cout << "No" << endl;
        else if(x==4||x==6||x==9||x==11){
            if(y==4||y==6||y==9||y==11){
                cout << "Yes" << endl;
            }else
                cout << "No" << endl;
        }else{
            if(y==1||y==3||y==5||y==7||y==8||y==10){
                cout << "Yes" << endl;
            }else
                cout << "No" << endl;
        }
        return 0;
}