#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <list>
#include <bitset>
#include <numeric>
#include <utility>
#define INF 1e9
#define MOD 1000000007
#define ll long long
#define int long long
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> p;
signed main(){
    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
    }
    vector<bool>b(n+3,false);
    for(int i=0;i<n;i++){
        if(i==p[i]){
            b[i]=true;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(b[i]){
            ans++;
            if(b[i+1]==true){
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}