#include<iostream>
#include<vector>
using namespace std;
int main(){
    int w,h,n;
    cin>>w>>h>>n;
    vector<vector<bool> >rect(w,vector<bool>(h,false));
    for(int i=0;i<n;i++)
    {
        int x1,y1,a;
        cin>>x1>>y1>>a;
        if(a==1){
            for(int i=0;i<x1;i++)
            {
                for(int j=0;j<h;j++)
                {
                    rect[i][j]=true;
                }
            }
        }
        else
        if(a==2){
            for(int i=x1;i<w;i++)
            {
                for(int j=0;j<h;j++)
                {
                    rect[i][j]=true;
                }
            }
        }
        else
        if(a==3){
            for(int i=0;i<w;i++)
            {
                for(int j=0;j<y1;j++)
                {
                    rect[i][j]=true;
                }
            }
            
        }
        else{
            for(int i=0;i<w;i++)
            {
                for(int j=y1;j<h;j++){
                    rect[i][j]=true;
                }
            }
        }
    }
    int count=0;
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(rect[i][j]==false)count++;
        }
    }
    cout<<count;
}