#include<iostream>
#include<vector>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>pic(h,vector<char>(w));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>pic[i][j];
        }
    }
    for(int i=0;i<2*h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout<<pic[(i)/2][j];
        }
        cout<<endl;
    }
}