#include <iostream>
#include <string>
using namespace std;
string binex(long long a){
    string s = "";
    while(a>0){
        if(a%2==0) s='0'+s;
        else s='1'+s;
        a/=2;
    }
    return s;
}
long long bin(int a){
    long long meu = 1;
    for(int i = 0;i<a;i++)meu*=2;
    return meu;
}
long long func(pair<long long,long long> pr[],int n,long long k){
    long long ans = 0;
    for(int i = 0;i<n;i++) if((k|pr[i].first) == k) ans+=pr[i].second;
    return ans;
}
int main(){
    int n;
    long long k;
    cin >> n >> k;
    pair<long long,long long> pr[n];
    for(int i = 0;i<n;i++) cin >> pr[i].first >> pr[i].second;
    long long ans = 0;
    string sk = binex(k);
    int sksize = sk.size();
    long long now = 0;
    for(int i = 0;i<sksize;i++){
        if(sk[i]=='1'){
            ans = max(ans,func(pr,n,now+bin(sksize-1-i)-1));
            now+= bin(sksize-1-i);
        }
    } 
    ans = max(ans,func(pr,n,k));
    cout << ans << endl;
}