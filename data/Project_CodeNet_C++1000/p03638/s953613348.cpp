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
    int h;
    int w;
    int n;
    vector<int> a;
    int tmp_a;
    cin >> h >> w;
    cin >> n;
    vector<vector<int>> ans(h, vector<int>(w));
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        a.push_back(tmp_a);
    }

    int idx=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            int tmp_j;
            if(i%2==0){
                tmp_j=j;
            }else{
                tmp_j=w-1-j;
            }
            if(a[idx]==0){
                idx++;
            }
            a[idx]--;
            ans[i][tmp_j]=idx+1;
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
