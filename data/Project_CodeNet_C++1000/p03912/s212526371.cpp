#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<int,int> x[m];
    vector<int> cnt(m, 0);
    while(n-- > 0){
        int k;  cin >> k;
        x[k%m][k]++;
        cnt[k%m]++;
    }
    vector<int> pa(m, 0);
    int ans = 0;
    for(int i = 0; 2*i <= m; i++){
        if((i+i)%m == 0){
            pa[i] = cnt[i]/2;
            cnt[i] -= pa[i];    // 後の処理を楽にするために
        }else{
            pa[i] = pa[m-i] = min(cnt[i], cnt[m-i]);
        }
        ans += pa[i];
    }
    for(int i = 0; i < m; i++){
        int aff = (cnt[i]-pa[i])/2;
        for(auto p : x[i]){
            ans += min(aff, p.second/2);
            aff -= min(aff, p.second/2);
        }
    }
    cout << ans << endl;
    return 0;
}