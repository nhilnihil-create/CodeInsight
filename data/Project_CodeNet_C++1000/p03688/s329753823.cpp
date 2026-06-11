#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N; cin>>N;
    vec_int a(N);
    int maxa=0;
    rep(i,N){
        cin>>a.at(i);
        if(a.at(i)>maxa)maxa=a.at(i);
    }

    int bigN=0;
    int smallN=0;
    rep(i,N){
        if(a.at(i)==maxa){
            bigN++;
        }else if(a.at(i)==maxa-1){
            smallN++;
        }
    }
    if(bigN+smallN<N){
        cout<<"No"<<endl;
        return 0;
    }

    //基本的にはmaxa色の色が存在していると考えてよい。
    // 唯一の例外は全員が違う色の時なので、それはここで処理しておく
    if(bigN==N&&maxa==N-1){
        cout<<"Yes"<<endl;
        return 0;
    }

    // というわけでmaxa色あるんだけれど、
    // このうち一人しか色を持っていない色がsmallN色ある。
    // 逆に言うとmaxa-smallN色については必ずダブりがないといけない
    // 
    // このような振り分けが可能であるかを考えないといけない。
    if(maxa<=smallN){
        cout<<"No"<<endl;
        return 0;

    }
    if((N-maxa)>=(maxa-smallN)){
        cout<<"Yes"<<endl;
        return 0;
    }else{
        cout<<"No"<<endl;
        return 0;

    }




    return 0;
}