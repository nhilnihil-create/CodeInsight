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

//typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

int main(){
    int n;
    int m;
    bool ok=false;
    cin >> n >> m;;
    vector<vector<int>> ab(n);
    int a;
    int b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        ab[a].push_back(b);
    }

    for(int i=0; i<ab[0].size(); i++){
        int tmp=ab[0][i];
        for(int j=0; j<ab[tmp].size(); j++){
            if(ab[tmp][j]==n-1){
                ok=true;
            }
        }
    }

    if(ok==true){
        cout << "POSSIBLE" << endl; 
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
