#include <iostream>

using namespace std;

int main(){
        long n,m;
        cin>>n>>m;

        cout<<min(n,m/2)+max((long)0,(m-n*2)/4)<<endl;

        return 0;
}
