#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,firstd,lastd;
    cin>>n;
    lastd=n%10;
    firstd=n;
    while(firstd>=10){
        firstd=firstd/10;
    }

    if(firstd==9||lastd==9) {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}

