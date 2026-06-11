#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    long long int sum=0;
    cin >> N;
    vector<long long int>a(3*N);
    for(int i=0;i<3*N;i++){
        cin>>a.at(i);
    }
    sort(a.begin(),a.end(),greater<long long int>());
    for(int i=0;i<2*N;i++){
        if(i%2==1){
            sum+=a.at(i);
        }
    }
    cout << sum;
}