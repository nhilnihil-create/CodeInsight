#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;

int a[310][310];
int used[310];
int cnt[310];

int main(){
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans=n;
    for(int i=n;i>=0;i--){
        for(int j=0;j<310;j++){
            cnt[j]=0;
        }
        bool ok=true;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(used[a[j][k]]&&k<m-1)continue;
                if(used[a[j][k]]&&k==m-1)ok=false;
                cnt[a[j][k]]++;
                break;
            }
        }
        if(ok==false)break;
        bool change=true;
        for(int j=0;j<310;j++){
            if(cnt[j]>i){
                change=false;
                used[j]=1;
            }
        }
        if(change)ans=i;
        else{
            i++;
        }
    }
    cout << ans << endl;
}