    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    int h,w;
    char x='A';
    cin>>h>>w;
    for(int i=1;i<=h;i++){
    for(int j=0;j<w;j++){
    cin>>s;
    if(s=="snuke"){
    cout<<char(x+j)<<i<<'\n';
    }
    }
    }
    return 0;
    }