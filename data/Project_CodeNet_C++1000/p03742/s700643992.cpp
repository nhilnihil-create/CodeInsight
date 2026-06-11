#include<iostream>
using namespace std;
#define int long long int
int32_t main()
{
    int x,y;
    cin>>x>>y;
    int answer=(abs)(x-y);
    if(answer>1)
       cout<<"Alice"<<endl;
    else
       cout<<"Brown"<<endl;
}
