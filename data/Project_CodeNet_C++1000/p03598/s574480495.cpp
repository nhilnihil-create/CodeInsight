#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int sum=0,y;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        y = k-x;
        if(x<=y)
            sum += x;
        if(x>y)
            sum += y;    
    }
    cout << sum*2 << endl;
}