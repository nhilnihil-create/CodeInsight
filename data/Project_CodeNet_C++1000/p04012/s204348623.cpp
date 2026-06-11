#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    string w;
    cin>>w;
    vector<long long> a(26,0);
    f(i,0,w.size()){
        a[w[i]-'a']++;
    }
    f(i,0,26){
        if(a[i]%2!=0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
