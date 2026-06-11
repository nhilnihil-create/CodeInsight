#include <iostream>

using namespace std;

int main()
{
    long long n,k,x,y,res=0;
    cin>>n>>k>>x>>y;
    for(int i=0;i<n;i++){
        if(k!=0){
            res+=x;
            k--;
        }
        else res+=y;
    }
    cout<<res<<endl;
    return 0;
}
