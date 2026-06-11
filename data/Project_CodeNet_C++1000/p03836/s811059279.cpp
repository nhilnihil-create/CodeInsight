#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=998244353;
const ll MAX=300000;
using vi=vector<int>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}

void unti(string s1){
    rep(i,(int)s1.size()){
        if(s1[i]=='R')cout<<"L";
        if(s1[i]=='L')cout<<"R";
        if(s1[i]=='U')cout<<"D";
        if(s1[i]=='D')cout<<"U";
    }
}


//////////////////////////////////////
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    int aa=a,bb=b,cc=c,dd=d;
    string s1="",s2="",s3="";
    
    while(aa<cc){
        s1+="R";
        aa++;
    }
    while(aa>cc){
        s1+="L";
        cc++;
    }
    while(bb<dd){
        s1+="U";
        bb++;
    }
    while(bb>dd){
        s1+="D";
        dd++;
    }
    
    cout<<s1;
    if(a==c||b==d){
        string s4="";
        if(a==c){
            s2="L";
            s3="R";
        }
        else{
            s2="R";
            s3="L";
        }
        s1=s2+s1+s3;
        cout<<s1;
        unti(s1);
        s4="";
        s4+=s1[0];
        s4+=s2+s2;
        cout<<s4;
        unti(s1);
        if(s1[0]=='U')cout<<"DD";
        if(s1[0]=='D')cout<<"UU";
        if(s1[0]=='R')cout<<"LL";
        if(s1[0]=='L')cout<<"RR";
        cout<<s3<<s3<<s1[0];
        return 0;
    }
    unti(s1);
    
    if(a<c&&b<d){
        s2+="DR";
        s3+="UL";
    }
    else if(a<c&&b>d){
        s2+="UR";
        s3+="DL";
    }
    else if(a>c&&b<d){
        s2+="DL";
        s3+="UR";
    }
    else{
        s2+="UL";
        s3+="DR";
    }

    
    string s4;
    s4+=s2+s1+s3;
    cout<<s4;
    unti(s4);

    cout<<endl;
    return 0;
}