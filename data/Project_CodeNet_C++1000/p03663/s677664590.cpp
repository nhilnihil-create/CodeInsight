#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

string tostring(int a){
    stringstream ss;ss<<a;return ss.str();
}


int toint(string s){
    stringstream ss(s);int d;ss>>d;return d;
}

int q(int a,int b){
    string A=tostring(a);
    string B=tostring(b);
    if(a<=b&&A<=B)return true;
    if(a>b&&A>B)return true;
    return false;
}


int q(int a){
    cout<<"? "<<a<<endl;
    char c;cin>>c;
    return c=='Y';
}

int L[20],R[20];

signed main(){


    L[0]=1;
    R[0]=9;
    for(int i=1;i<12;i++){
        L[i]=L[i-1]*10;
        R[i]=R[i-1]*10+9;
    }

    vint X(12),Y(12);
    rep(i,12){
        X[i]=q(L[i]);
        Y[i]=q(R[i]);
    }

    int mi=LLONG_MAX;
    int ma=LLONG_MIN;
    rep(i,12){
        if(X[i]&&Y[i]){
            chmin(mi,i);
            chmax(ma,i);
        }
    }

    int len;
    if(mi==0&&ma==11)len=0;
    else if(mi==0)len=ma;
    else len=mi;

    len++;
    string beet(15,'9');
    string ans(len,'0');

    for(int i=0;i<len;i++){
        int lb=-1,ub=9;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            beet[i]=mid+'0';
            if(q(toint(beet)))ub=mid;
            else lb=mid;
        }
        if(i==0)chmax(ub,1);
        ans[i]=ub+'0';
        beet[i]=ub+'0';
    }

    cout<<"! "<<ans<<endl;
}
