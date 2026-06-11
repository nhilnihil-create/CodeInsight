#include<bits/stdc++.h>
using namespace std;
#define con continue
#define bk break
#define LL long long
#define db double
#define pt cout<<'\n'
#define ms(a, b) memset((a), (b), sizeof(a))
#define mp make_pair
#define endl '\n'
int inf=2147483647;const long long ll =9223372036854775807,ninf=1000000000;const double eps = 1e-6; const long long nll =1000000000000000000;
#define sz size()
#define len(X) strlen(X)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ULL unsigned long long
#define de cout<<"test"<<endl;
#define st system("pause");
#define F first
#define S second
class SlimeXSlimesCity
{
    public:
int merge(vector <int> population)
{

}
};
int f[305][305]={};
int num[305][305]={};
int main()
{
    int a;
    while(cin>>a){
        int no=0;
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                cin>>f[i][j];
            }
        }
        for(int k=0;k<a;k++){
            for(int i=0;i<a;i++){
                for(int j=0;j<a;j++){
                    if(k!=j&&i!=k&&f[i][k]+f[k][j]<f[i][j]){
                        no=1;
                    }
                     if(k!=j&&i!=k&&f[i][k]+f[k][j]==f[i][j]){
                        num[i][j]=1;
                    }
                }
            }
        }
        if(no){
            cout<<-1<<endl;
            con;
        }
        LL ans=0;
            for(int i=0;i<a;i++){
                for(int j=i+1;j<a;j++){
              if(!num[i][j])
                ans+=f[i][j];
                }
            }
        cout<<ans<<endl;
    }

    return 0;
}
