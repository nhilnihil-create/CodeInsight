#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,M;
    cin >> N >>M;
    vector<vector<int>> A(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }
    int l=0;
    int r =N;
    while(l+1<r){
        int mid =(l+r)/2;
        // cerr <<"mid=" << mid <<endl;
        set<int> banned;
        bool ok = true;
        while(banned.size()<M){
            ok = true;
            map<int,int> mp;
            for(int i=0;i<N;i++){
                int t=0;
                while(t < M-1 &&banned.find(A[i][t])!= banned.end()){
                    t++;
                }
                mp[A[i][t]]++;
            }
            // cerr << banned.size() << endl;
            for(auto itr = mp.begin();itr != mp.end();itr++){
                // cerr <<"num="<< itr->first<< "val="<<itr->second << endl;
                if(itr->second > mid){
                    banned.insert(itr->first);
                    ok = false;
                }
            }
            if(ok){
                break;
            }
        }
        if(ok){
            r = mid;
        }else{
            l = mid;
        }
        
    }
    cout << r << endl;

    return 0;
}