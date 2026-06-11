#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int64_t K;
    cin >> N >> K;
    /*
    vector<int> v;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        for(int j=0; j<b; j++){
            v.push_back(a);
        }
    }
    sort(v.begin(), v.end());
    cout << v.at(K-1) << endl;
    */
   vector<int64_t> v(100001, 0);
   for(int i=0; i<N; i++){
       int a,b;
       cin >> a >> b;
       v.at(a) += b;
   }
   for(int i=0; i< 100001; i++){
       if(K<=v.at(i)){
           cout << i << endl;
           break;
       }
       K -= v.at(i);
   }
}