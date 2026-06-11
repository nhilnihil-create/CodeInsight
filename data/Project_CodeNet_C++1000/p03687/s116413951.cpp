#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
long double eps = 1e-9;
long double pi = acos(-1);



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    string ss;
    cin>>ss;
    int ans = 1e8;
    for(char c = 'a';c<='z';c++){
        string s = ss;
        int ret = 0;
        bool pos = false;
        int n = s.size();
        bool same = true;
        for(int i=0;i<n;i++){
            if(s[i] == c)pos=1;
            else same = false;
        }
        if(same){
            cout << 0 << endl;
            return 0;
        }
        if(!pos)continue;
        while(true){
            string t;
            int n = s.size();
            int cnt = 0;
            for(int i=0;i<n-1;i++){
                if(s[i]==c||s[i+1]==c){
                    cnt++;
                    t+=c;
                }
                else t += '.';
            }
            ret++;
            if(cnt == n-1)break;
            swap(t,s);
        }
        chmin(ans,ret);
    }
    cout << ans << endl;

}