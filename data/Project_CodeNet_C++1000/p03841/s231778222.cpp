#include<bits/stdc++.h>
using namespace std;
int f[250009];
int x[509];
int S[509];
main(){
    int n;
    cin >> n;
    vector<pair<int,int> > X;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        f[x[i]] = i;
        X.push_back({x[i],i});

    }
    sort(X.begin(), X.end());
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < X[i].second - 1; j++)
            v.push_back(X[i].second),S[X[i].second]++;
    }
    int k = 0;
    for(int i = 1; i <= n*n; i++){
        if(f[i]){
            if(S[f[i]]){
                cout<<"No"<<endl;
                return 0;
            }
            for(int j = 0; j < n - f[i]; j++)
                v.push_back(f[i]),
                S[f[i]]++;
            continue;

        }
        if(k >= v.size()) {
            cout << "No"<<endl;
            return 0;
        }
        f[i] = v[k];
        S[f[i]] --;
        k ++;
    }
    cout<< "Yes"<<endl;
    for(int i = 1; i <= n * n; i++){
        cout << f[i] <<" ";
    }
    cout<<endl;


}
