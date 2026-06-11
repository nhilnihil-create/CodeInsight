#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

void deb(vector<int> &da){
    int x=da.size();
    rip(i,x,0){
        if(i==x-1){
            cout << da[i] << endl;
        }else{
            cout << da[i] << ' ';
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> da(n,vector<int>(m));
    rip(i,n,0){
        rip(j,m,0){
            cin >> da[i][j];
            da[i][j]--;
        }
    }
    vector<int> co(m,0);
    vector<bool> ju(m,true);
    vector<int> po(n,0);
    int no=0,ans=n+1;
    rip(i,n,0){
        co[da[i][0]]++;
    }
    rip(i,m-1,0){
        //deb(co);
        int ma=0;
        rip(j,m,0){
            if(co[j]>ma){
                ma=co[j];
                no=j;
            }
        }
        ans=min(ans,ma);
        ju[no]=false;
        rip(j,n,0){
            while(!ju[da[j][po[j]]]){
                co[da[j][po[j]]]--;
                po[j]++;
                co[da[j][po[j]]]++;
            }
        }
    }
    int ma=0;
    rip(i,m,0){
        if(co[i]>ma){
            ma=co[i];
        }
    }
    ans=min(ans,ma);
    cout << ans << endl;
}