using namespace std;
#include<iostream>
int main(){
    int n,b=0,a=1;
    cin>>n;
    for(int i=0;i<n;i++){
        b+=a;
        a++;
       
    }
    std::cout << b << std::endl;
}
