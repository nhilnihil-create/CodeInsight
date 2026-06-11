#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    string a,b;
    cin >> a >> b;
    if(a.size()>b.size()){
        cout << "GREATER" << endl;
    }else if(a.size()<b.size()){
        cout << "LESS" << endl;
    }else{
        rep(i,a.size()){
            if(a[i]>b[i]){
                cout << "GREATER" << endl;
                return 0;
            }else if(a[i]<b[i]){
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
    }
    return 0;
}