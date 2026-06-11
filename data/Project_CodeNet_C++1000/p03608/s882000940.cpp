#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
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
 
//#define MOD 1000000007
//#define MAX 100100
#define NIL -1
//#define INFTY 1000000000000000000

LL N;
vector<vector<LL>> d(300, vector<LL>(300, NIL));

void floyd(){
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(d[i][k]==NIL || d[k][j]==NIL){
                    continue;
                }
                if(d[i][j]==NIL){
                    d[i][j]=d[i][k]+d[k][j];
                }else{
                    d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
    }
}

int main(){
    LL M;
    LL R;
    cin >> N >> M >> R;
    vector<LL> r(R);
    for(LL i=0; i<R; i++){
        cin >> r[i];
        r[i]--;
    }
    sort(r.begin(), r.end());

    LL a;
    LL b;
    LL c;
    for(LL i=0; i<M; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b]=c;
        d[b][a]=c;
    }

    floyd();

    LL min_sum=NIL;
    LL sum;
    do{
        sum=0;
        for(LL i=0; i<R-1; i++){
            sum+=d[r[i]][r[i+1]];
        }
        if(min_sum==NIL){
            min_sum=sum;
        }else{
            min_sum=min(min_sum,sum);
        }
    }while(next_permutation(r.begin(), r.end()));

    cout << min_sum << endl;

    return 0;
}
