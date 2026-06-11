#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
        mp[a[i]] ++;
    }
    int max=0,smax=0,cnt=0;
    for(int i = 0;i < n;i ++){
        int sub=mp.rbegin()->first-a[i];
        if(sub==0){
            if(smax==max) cnt ++;
            if(smax>max) {cnt=1,max=smax;}
            smax=0;
        }else if(sub>smax) smax = sub;
        mp[a[i]] --;
        if(!mp[a[i]]) mp.erase(a[i]);
    }
    cout << cnt << endl;
    return 0;
}