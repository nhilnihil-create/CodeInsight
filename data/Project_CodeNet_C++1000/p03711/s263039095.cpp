#include <iostream>
using namespace std;

int main() {
    int x[2];cin>>x[0]>>x[1];
    for(int i=0;i<2;++i){
        if(x[i]==2)x[i]=2;
        else if(x[i]==4||x[i]==6||x[i]==9||x[i]==11)x[i]=1;
        else x[i]=0;
    }
    if(x[0]==x[1])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}