#include<iostream>
#include<vector>
using namespace std;

bool check(int n,vector<bool>digit){
    while(n!=0){
        if(digit[n%10]==true){
            return false;
        }
        n/=10;
    }
    return true;
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<bool>digits(10,false);
    for(int i=0;i<k;i++)
    {
        int element;
        cin>>element;
        digits[element]=true;
    }
    while(1){
        if(check(n,digits)){
            cout<<n;
            return 0;
        }
        n++;
    }
}