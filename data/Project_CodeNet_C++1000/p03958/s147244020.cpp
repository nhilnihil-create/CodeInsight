#include <bits/stdc++.h>

using namespace std;

int main(){
    int K,T,run,lst=-1,ans=0,sum=0;
    cin >> K >> T;
    vector<int> a(T);
    for(int i=0;i<T;i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(),a.end());

    if(a.back()<=1+sum-a.back()){
        cout << 0 << endl;
    }else{
        cout << 2*a.back()-sum-1 << endl;
    }
}
