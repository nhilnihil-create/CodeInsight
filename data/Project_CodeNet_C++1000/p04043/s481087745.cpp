#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i,five=0,seven=0;
    vector<int>v(3);
    for(i=0;i<3;i++){
        cin>>v[i];
        if(v[i]==5)
        five++;
        else if(v[i]==7)
        seven++;
    }
    if(five==2&&seven==1)
    cout<<"YES";
    else
    cout<<"NO";
    cout<<endl;
    return 0;
}
