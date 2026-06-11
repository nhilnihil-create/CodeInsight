#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority queue
#include<deque>//double_ended queue
using namespace std;
int main()
{ 
    int h,w,n;
    cin>>h>>w>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //せいぜい1万通りなので全部記述する。
    vector<vector<int> > v;
    vector<int> c;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            c.push_back(i);
            if(c.size()==w){
                v.push_back(c);
                c.clear();            }
        }
    }
    int cnt=0;
    for(int i=0;i<h;i++){
        if(cnt==0){
            cnt=1;
            c=v.back();
            v.pop_back();
            for(int j=0;j<w-1;j++){
                cout<<c[j]<<' ';
            }
            cout<<c[w-1]<<endl;
        }
        else{
            cnt=0;
            c=v.back();
            v.pop_back();
            reverse(c.begin(),c.end());
            for(int j=0;j<w-1;j++){
                cout<<c[j]<<' ';
            }
            cout<<c[w-1]<<endl;
        }

    }
    return 0;
}