#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>

using namespace std;

#define INT_MAX_VALUE 2147483647
#define LONG_LONG_MAX_VALUE 9223372036854775807
#define ll long long
#define ld long double

struct XX{
    int s;
    int t;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.t) == (riRight.t)){
            return riLeft.s < riRight.s;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.t) < (riRight.t);
    }
};


//map<long long,long long> prime_f(long long n){
//    map<long long,long long>res;
//    for(int i=2;i*i<=n;i++){
//        while(n%i==0){
//            ++res[i];
//            n/=i;
//        }
//    }
//    if(n!=1)res[n]=1;
//    return res;
//}


int n;
//int dat[2*10000000];
//int dat2[2*10000000];
int dat[10];
int dat2[10];

void init(int n_){
    n=1;
    while(n<n_)n*=2;
    for(int i=0;i<2*n-1;i++){
        dat[i]=0;
        dat2[i]=0;
    }
}

void initset(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=dat[k*2+1]+dat[k*2+2];
    }
}

//[a,b)の間を[l,r]区間で比較しアップデート
//引数のindexに注意
//nは固定。initで計算すみ
//update2(L[i],R[i]+1,0,0,n,D[i]);
void update2(int a,int b,int k,int l,int r,int v){//v更新値、区間は0-index
    if(r<=a || b<=l)return;
    if(a<=l && r<=b){
        dat[k]+=dat2[k];
        if(r-l>1){
            dat2[k*2+1]+=dat2[k]/2;
            dat2[k*2+1]+=dat2[k]/2;
        }
        dat2[k]=v*(r-l);
        return;
    }else{
        update2(a,b,k*2+1,l,(l+r)/2,v);
        update2(a,b,k*2+2,(l+r)/2,r,v);
        return;
    }
}

int query(int a,int b,int k,int l,int r){
    if(r<=a || b<=l)return 0;
    if(a<=l && r<=b){
        dat[k]+=dat2[k];
        if(r-l>1){
            dat2[k*2+1]+=dat2[k]/2;
            dat2[k*2+1]+=dat2[k]/2;
        }
        dat2[k]=0;
        return dat[k];
    }
    else{
        int vl=query(a,b,k*2+1,l,(l+r)/2);
        int vr=query(a,b,k*2+2,(l+r)/2,r);
        return vl+vr;
    }
}





ll cmb(ll nn, ll kk){
    if(kk==0)return 1;
    ll bunsi=1;
    ll bunbo=1;
    for(int i=0;i<kk;i++){
        bunsi*=(nn-i);
        bunbo*=(kk-i);
    }
    return bunsi/bunbo;
}
int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs("a.txt");//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int H,W,N;
    cin >> H>>W>>N;
    int a[100000];
    int b[100000];
    for(int i=0;i<N;i++){
        cin >> a[i]>>b[i];
    }
    vector<XX>ans;
    int dx[] = {2,1,0,2,1,0,2,1,0}, dy[] = {2,2,2,1,1,1,0,0,0};
    for(int i=0;i<N;i++){
        for(int j=0;j<9;j++){
            XX tmp;
            if(a[i]-dx[j]<1 || b[i]-dy[j]<1)continue;
            if(a[i]-dx[j]>H-2 || b[i]-dy[j]>W-2)continue;
            tmp.s=a[i]-dx[j];
            tmp.t=b[i]-dy[j];
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(),ans.end(),xxGreater());
    int ans_2[10];
    for(int i=0;i<10;i++){
        ans_2[i]=0;
    }
    int sum=0;
    if(ans.size()>0){
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i].s==ans[i+1].s && ans[i].t==ans[i+1].t){
                sum++;
            }else{
                ans_2[sum]++;
                sum=0;
            }
        }
        ans_2[sum]++;
    }
    
    int ans3=0;
    for(int i=0;i<9;i++){
        ans3+=ans_2[i];
    }
    ll tmptmp=(ll)(H-2)*(ll)(W-2)-ans3;
    cout << tmptmp << endl;
    for(int i=0;i<9;i++){
        cout << ans_2[i] << endl;
    }
    
    //ここまで
    //cout << "ans" << endl;
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}

