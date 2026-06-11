#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <bitset>
#include <cmath>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;

vector<int> ans(0);

void dfs(vector<vector<int>> &da, int now,vector<bool> &ju){
    int size=da[now].size();
    rip(i,size,0){
        if(ju[da[now][i]]){
            ju[da[now][i]]=false;
            ans.push_back(da[now][i]);
            dfs(da, da[now][i],ju);
            break;
        }
    }
    return;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> da(n,vector<int>(0));
    int a, b;
    rip(i,m,0){
        cin >> a >> b;
        a--;b--;
        da[a].push_back(b);
        da[b].push_back(a);
    }
    ans.push_back(0);
    vector<bool> ju(n,true);
    ju[0]=false;
    dfs(da,0,ju);
    reverse(all(ans));
    dfs(da,0,ju);
    int size=ans.size();
    printf("%d\n",size);
    for(int i=size-1;i>-1;i--){
        if(i==0){
            cout << ans[i] + 1 << endl;
        }
        else{
            cout << ans[i] + 1 << ' ';
        }
    }
}