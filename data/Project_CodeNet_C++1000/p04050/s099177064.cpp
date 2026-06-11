# include <iostream>
using namespace std;
int v[110],n,m,i,nr;
int main () {
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>v[i];
        nr+=v[i]%2;
    }
    if(nr>2){
        cout<<"Impossible";
        return 0;
    }
    if(m==1){
        if(v[1]==1)
            cout<<"1\n1\n1\n";
        else
            cout<<v[1]<<"\n"<<2<<"\n"<<1<<" "<<v[1]-1<<"\n";
        return 0;
    }
    for(i=1;i<=m;i++)
        if(v[i]%2==1)
            swap(v[i],v[1]);
    for(i=2;i<=m;i++)
        if(v[i]%2==1)
            swap(v[i],v[m]);
    for(i=1;i<=m;i++)
        cout<<v[i]<<" ";
    cout<<"\n";
    if(v[1]==1)
        cout<<m-1<<"\n";
    else
        cout<<m<<"\n"<<v[1]-1<<" ";
    for(i=2;i<m;i++)
        cout<<v[i]<<" ";
    cout<<v[m]+1<<"\n";
    return 0;
}
