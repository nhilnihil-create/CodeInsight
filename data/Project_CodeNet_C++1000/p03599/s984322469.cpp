#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    a*=100;
    b*=100;
    vector<vector<int>>x(f+1,vector<int>(f+1,0));//合計iグラムで、砂糖がjグラムのものはあるか
    x[0][0]=1;
    int w=a,s=0;
    for(int i=0;i<=f;i++){
        for(int j=0;j<=f;j++){
            if(x[i][j]){
                if(e*(i-j)>=100*j && j*w>i*s){
                    w=i;
                    s=j;
                }
                if(i+a<=f)x[i+a][j]=1;
                if(i+b<=f)x[i+b][j]=1;
                if(i+c<=f)x[i+c][j+c]=1;
                if(i+d<=f)x[i+d][j+d]=1;
            }
        }
    }
    cout<<w<<" "<<s<<endl;
    return 0;
}