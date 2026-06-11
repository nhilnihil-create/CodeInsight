#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> pack;
    pack.push_back(a);
    pack.push_back(b);
    pack.push_back(c);
    sort(pack.begin(),pack.end());
    if (pack[0]+pack[1] == pack[2]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}