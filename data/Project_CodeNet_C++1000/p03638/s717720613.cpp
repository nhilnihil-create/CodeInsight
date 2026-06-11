#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main(){
    FIN;
    int h,w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    int ans[h][w];
    int i=0,j=0;
    int color = 1;
    int count_num = 0;
    int count_color = 0;
    int flag = 0;

    for(int p=0;p<h*w;p++){
        ans[i][j] = color;
        count_color++;
        if(count_color == a[color-1]){
            color++;
            count_color = 0;
        }

        count_num++;
        if(count_num % w == 0){
            i++;
            flag = 1-flag;
            if(flag == 0) j--;
            else j++;
        }

        if(flag == 0) j++;
        else j--;

    }


    for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
            cout << ans[x][y] << " ";
        }
        cout << endl;
    }


    return 0;
}
