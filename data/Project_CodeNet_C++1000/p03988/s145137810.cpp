#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define imp { cout << "Impossible" << endl; return 0; }
#define pos { cout << "Possible" << endl; return 0; }


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    int a[n];
    int d = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        d = max(d,a[i]);
    }
    sort(a,a+n);
    int low = (d+1)/2;
    if(a[0] != low) imp;
    int now = 1;
    for(int i=low;i<=d;i++){
        int cnt = 0;
        while(now<n && a[now] == i){
            cnt++;
            now++;
        }
        if(i==low){
            if(d%2 && cnt!=1) imp;
            if(d%2==0 && cnt!=0) imp;
            continue;
        }
        if(cnt<2) imp;
    }
    pos;



}