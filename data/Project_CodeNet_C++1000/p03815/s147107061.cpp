#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    cin>>x;
    long long answer;
    long double frac=ceil((double)x/11);
    answer=2*((frac));
    if(answer/2*11-5>=x){
        answer=answer-1;
    }
    cout<<answer<<endl;
}
