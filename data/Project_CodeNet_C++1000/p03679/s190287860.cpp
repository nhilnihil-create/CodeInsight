#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    b *= -1;
    int sum = b + c;
    if(sum <= a && sum > 0) cout<<"safe"<<endl;
    else if(sum <= 0 && sum >= b) cout<<"delicious"<<endl;
    else cout<<"dangerous"<<endl;
    return 0;
}
