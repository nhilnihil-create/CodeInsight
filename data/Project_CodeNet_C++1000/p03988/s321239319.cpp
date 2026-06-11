#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll maxDepth = a.back();
    bool ok =true;
    if(maxDepth %2 ==0){
        int t = maxDepth/2;
        for(int i=0;i<N;i++){
            if(a[i] != t){
                ok = false;
                break;
            }
            int num =1;
            while(i<N-1 && a[i] == a[i+1]){
                num++;
                i++;
            }
            if(t == maxDepth/2){
                if(num!=1){
                    ok = false;
                    break;
                }
            }else if(num<2){
                ok = false;
                break;
            }
            t++;
        }
    }else{
        int t = (maxDepth+1)/2;
        for(int i=0;i<N;i++){
            if(a[i] != t){
                ok = false;
                break;
            }
            int num =1;
            while(i<N-1 && a[i] == a[i+1]){
                num++;
                i++;
            }
            if(t == (maxDepth+1)/2){
                if(num!=2){
                    ok = false;
                    break;
                }
            }else if(num<2){
                ok = false;
                break;
            }
            t++;
        }

    }
    if(ok){
        cout <<"Possible" << endl;
    }else{
        cout <<"Impossible" << endl;
    }

    return 0;
}