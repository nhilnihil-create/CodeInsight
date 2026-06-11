#include <iostream>
using namespace std;

int main(void){
    long long n,m,ans;
    cin>>n>>m;
    if(n*2>=m){
        cout<<(m/2)<<endl;
    }else{
        cout<<(n+(m-n*2)/4)<<endl;
    }
}