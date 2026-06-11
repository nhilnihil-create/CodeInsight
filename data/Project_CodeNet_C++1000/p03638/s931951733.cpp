#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){
    int h,w,n; cin >> h >> w >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> prec(h*w);
    int k=0,l=0;
    while(k<h*w){
        rep(i,a[l]){
            prec[k] = l+1;
            k++;
        }
    l++;
    }

    int ans[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i%2==0){
                ans[i][j] = prec[i*w+j]; 
            }else{
                ans[i][w-j-1] = prec[i*w+j];
            }
        }
    }
    rep(i,h){
        rep(j,w){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}