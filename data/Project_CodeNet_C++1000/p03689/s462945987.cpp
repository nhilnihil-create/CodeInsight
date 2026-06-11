#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,a,b;
    ll sum=0;
    cin>>h>>w>>a>>b;
    ll ans[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if((i+1)%a==0 && (j+1)%b==0){
                ans[i][j]=-1e3*(a*b-1)-1;
            }
            else{
                ans[i][j]=1e3;
            }
            sum+=ans[i][j];
        }
    }
    if(sum<=0){
        cout <<"No"<<endl;
        return 0;
    }
    cout <<"Yes"<<endl;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

