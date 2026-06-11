#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

signed main(void){
  
    long double n,a,b; cin>>n>>a>>b;
    vector <int> nums(n);
    vector <vector<int>> com(52,vector <int>(52));
    
    com[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];        
        }
    }
    rep(i,n) cin>>nums[i];
    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());
    int f,l;
    f = nums[0], l = nums[a-1];
    //cout<<setprecision(10)<<accumulate(nums.begin(), nums.begin() + a,0.0)/a<<endl;
    printf("%.10Lf\n",accumulate(nums.begin(), nums.begin() + a,0.0)/a);
    
    if(f == l){
        int cnt = count(all(nums), f);
        
        int ans = 0;
        for(int i=a;i<=b;i++){
            ans += com[cnt][i];
            //cout<<com[cnt][i]<<endl;
        }
        cout<<ans<<endl;
    }else{
        int cnt = 0, call=0;
        rep(i,a){
            if(l == nums[i]) cnt++;
        }
        rep(i,n) if(l==nums[i]) call++;
        cout<<com[call][cnt]<<endl;
    }
}
