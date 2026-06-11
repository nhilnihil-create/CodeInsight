#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n,t;
    cin >> n>>t;
    vector<long long> T(n);
    for (long long i = 0; i < n;i++){
        cin >> T[i];
    }
    long long sum = 0;
    for(int i = 0;i<n-1;i++){
        if(T[i+1]-T[i]<t){
            sum +=T[i+1]-T[i];
        }else{
            sum+=t;

        }
    }

    cout << sum+t<<endl;

}