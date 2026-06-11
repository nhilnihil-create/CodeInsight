#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;

    int answer = 0;
    int max_div=0;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    FOR(i,1,n+1){
        int now = i;
        int count = 0;
        while(now%2==0){
            count++;
            now/=2;
        }
        if(count > max_div){
            answer = i;
            max_div = count;
        }
    }
    cout << answer << endl;
    return 0;
}