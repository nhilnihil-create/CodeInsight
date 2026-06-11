#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

int main(){
    ll h,w;
    cin >> h>> w;
    ll ans1,ans2,ans3,ans4;
    if(h%3==0||w%3==0){
        cout<<0<<endl;
        return 0;
    }else{
        ll hh;
        if(h%3==1){
            hh=h/3;
        }else{
            hh=h/3+1;
        }
        ll s1=w*(hh);
        ll s2=(w/2)*(h-hh);
        ll s3=(w-w/2)*(h-hh);
        cerr<<s1<<' '<<s2<<' '<<s3<<endl;
        ans1=max(s1,max(s2,s3))-min(s1,min(s2,s3));
        s1=w*hh;
        s2=w*((h-hh)/2);
        s3=w*(h-hh-((h-hh)/2));
        ans3=max(s1,max(s2,s3))-min(s1,min(s2,s3));
        ll ww;
        if(w%3==1){
            ww=w/3;
        }else{
            ww=w/3+1;
        }
        s1 =h*(ww);
        s2=(h/2)*(w-ww);
        s3=(h-h/2)*(w-ww);
        cerr<<s1<<' '<<s2<<' '<<s3<<endl;
        ans2=max(s1,max(s2,s3))-min(s1,min(s2,s3));
        s1=ww*h;
        s2=h*((w-ww)/2);
        s3=h*(w-ww-((w-ww)/2));
        ans4=max(s1,max(s2,s3))-min(s1,min(s2,s3));
    }
    ll ans=min(min(ans1,ans4),min(ans2,ans3));
    cout<<ans<<endl;
    return 0;
}