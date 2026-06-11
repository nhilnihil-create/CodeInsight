#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
#define np basic_string::npos
int main(void){
    int n,mm=0,i=1;
    cin>>n;
    while(mm<n){
        mm+=i;
        i++;
    }
    cout<<i-1<<endl;
}