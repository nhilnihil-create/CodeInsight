#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int N,K,X,Y;

    cin>>N>>K>>X>>Y;

    cout<<min(K,N)*X+(N-K)*Y*(N-K>0)<<endl;
}
