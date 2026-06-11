#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define BIL ((ll)1e9)
#define MOD ((ll)1e9+7)
#define INF (1LL<<60)           //1LL<<63でオーバーフロー
#define inf (1<<29)             //1<<29でオーバーフロー

int main(int argc,char* argv[]){
    int n,a,b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    int pass=0;
    int passfor=1;
    for(int i=0;i<n;i++){
        if(s[i]=='a' && pass<a+b){
            cout << "Yes" << endl;
            pass++;
            continue;
        }
        if(s[i]=='b' && pass<a+b){
            if(passfor<=b){
                cout << "Yes" << endl;
                pass++;
                passfor++;
                continue;
            }
        }
        cout << "No" << endl;
    }

    return 0;
}
