#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
struct segment_tree{
    long n = 1;
    vector<long long> data;
    segment_tree(int a){
        while(n<a) n*=2;
        data.push_back(0);
        for(int i = 1;i<2*n;i++) data.push_back(0);
    }
    //segment treeの大きさ取得
    long nreturn(){
        return n;
    }
    //0-indexでk番目の値をaに変更
    void change(long k,long long a){
        k+=n;
        data[k] = a;
        while(k>1){
            k/=2;
            data[k] = data[2*k]+data[2*k+1];
        }
        return;
    }
    //区間[a,b)の総和:呼ぶときはrsq(a,b,1,0,n)
    long long rsq(long long a,long long b,long long k,long long l,long long r){
        if(a>=r || b<=l) return 0;
        if(a<=l && b>=r) return data[k];
        long long teml = rsq(a,b,2*k,l,(l+r)/2);
        long long temr = rsq(a,b,2*k+1,(l+r)/2,r);
        return teml+temr;
    }
};
int main(){
    long n;
    long long k;
    cin >> n >> k;
    long long a[n];
    set<long long> tmpst;
    tmpst.insert(0);
    rep(i,n){
        cin >> a[i];
        a[i]-=k;
    }
    long long csum[n+1];
    csum[0] = 0;
    rep(i,n){
        csum[i+1]=csum[i]+a[i];
        tmpst.insert(csum[i+1]);
        //cout << csum[i+1] << endl;
    }
    map<long long,int> mp;
    long cnt = 0;
    for(auto itr = tmpst.begin();itr!=tmpst.end();itr++){
        mp[*itr] = cnt;
        cnt++;
        //cout << *itr << endl;
    }
    segment_tree tree(tmpst.size());
    long long ans = 0;
    long long tmp;
    tree.change(mp[0],1);
    //cout << mp[0] << endl;
    rep(i,n){
        tmp = mp[csum[i+1]];
        ans+=tree.rsq(0,tmp+1,1,0,tree.n);
        //cout << "csum: "<< csum[i+1] << " tmp: " << tmp << " ans: "<< ans << endl;
        tree.change(tmp,tree.data[tree.n+tmp]+1);
    }
    cout << ans << endl;
}