#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    vector<int>t(n);
    for(int i=0;i<n;i++){
        cin>>t.at(i);
    //    cout<<"t["<<i<<"]"<<t.at(i)<<endl;
    }

    cin>>m;
    vector<int>p(m);
    vector<int>x(m);

    for(int i=0;i<m;i++){
        cin>>p.at(i)>>x.at(i);
    //    cout<<p.at(i)<<x.at(i)<<endl;
    }
    
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            
            if(j+1==p.at(i)){
                sum+=x.at(i);
            }else{
                sum+=t.at(j);
            }

        }
        cout<<sum<<endl;
    }
    cout<<endl;
}