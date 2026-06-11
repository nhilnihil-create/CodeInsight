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
 
//#define MOD 1000000007
#define MAX 100100
//#define NIL -1

vector<vector<int>> ab(MAX);
vector<vector<LL>> c(MAX);
vector<LL> d(MAX);
vector<bool> is_visit(MAX, false);

void dfs(int s){
    if(ab[s].size()==0){
        return;
    }

    for(int i=0; i<ab[s].size(); i++){
        if(is_visit[ab[s][i]]==true){
            continue;
        }
        d[ab[s][i]]=d[s]+c[s][i];
        is_visit[ab[s][i]]=true;
        dfs(ab[s][i]);
    }

    return;
}

int main(){
    int n;
    int q;
    int k;
    int tmp_a;
    int tmp_b;
    LL tmp_c;
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> tmp_a >> tmp_b >> tmp_c;
        tmp_a--;
        tmp_b--;
        ab[tmp_a].push_back(tmp_b);
        ab[tmp_b].push_back(tmp_a);
        c[tmp_a].push_back(tmp_c);
        c[tmp_b].push_back(tmp_c);
    }

    cin >> q >> k;
    k--;
    vector<int> x;
    vector<int> y;
    int tmp_x;
    int tmp_y;

    for(int i=0; i<q; i++){
        cin >> tmp_x >> tmp_y;
        tmp_x--;
        tmp_y--;
        x.push_back(tmp_x);
        y.push_back(tmp_y);
    }

    is_visit[k]=true;
    d[k]=0;
    dfs(k);

    for(int i=0; i<q; i++){
        cout << d[x[i]]+d[y[i]] << endl;
    }

    return 0;
}
