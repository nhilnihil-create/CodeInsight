#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int x[m];
    int y[m];
    vector<bool>red(n+1,false);
    red[1] = true;
    vector<int>balls(n+1,1);
    for(int i=0;i<m;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<m;i++){
        balls[x[i]]--;
        balls[y[i]]++;;
        if(red[x[i]])red[y[i]] = true;
        if(balls[x[i]]==0)red[x[i]]=false;
    }
    int ans = 0;
    for(int i=1;i<=n;i++)if(red[i])ans++;
    cout << ans << endl;
}