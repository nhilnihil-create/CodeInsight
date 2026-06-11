#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

vector<LL> prime_list(1100, 0);

void factorize_gen(LL n){
    for(LL i=2; i*i<=n; i++){
        if(n%i!=0){
            continue;
        }
        LL num=0;
        while(n%i==0){
            num++;
            n/=i;
        }
        prime_list[i]+=num;
    }
    if(n!=1){
        prime_list[n]+=1;
    }

    return;
}

int main() {
    LL n;
    LL ans=1;
    cin >> n;
    for(LL i=2; i<=n; i++){
        factorize_gen(i);
    }

    for(LL i=0; i<=n; i++){
        ans=ans*(prime_list[i]+1);
        ans=ans%MOD;
    }

    cout << ans << endl;

    return 0;
}