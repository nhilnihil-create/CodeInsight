#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1000000007;

/*WA→解説
mapを使うかvectorをソートして使うかの違い？
kCa+kC(a+1)+,,+kC(b-1)+kCb
の部分で、解説ではC[n][k].k>nが0なので問題ないが、
nCkがnCk[n][0]~nC[n][n]までしか定義してなく、b=min(b,k)にする必要あり
*/
int main(){
    vector<vector<long long>> nCk(51);
    nCk[0].push_back(1);
    rep(i,50){
        nCk[i+1].push_back(1);//nC0
        rep(j,nCk[i].size()-1)//nC1~nC(n-1)
            nCk[i+1].push_back(nCk[i][j]+nCk[i][j+1]);
        nCk[i+1].push_back(1);//nCn
        /*for(auto num:nCk[i+1]) cout<<num<<" ";
        cout<<endl;*/
    }
    
    int n,a,b;
    cin>>n>>a>>b;
    map<long long,int> minuscount; //vに-をかけて保存、大きい順に取り出す
    rep(i,n){
        long long v;
        cin>>v;
        minuscount[-1*v]++;
    }
    //大きい順にa個の値選ぶとき、すべて同じかそうでないか
    //cout<<minuscount.begin()->first<<" "<<minuscount.begin()->second<<endl;
    int k=minuscount.begin()->second;
    if(k>=a){
        cout<<-1*minuscount.begin()->first<<endl;
        //kCa+kC(a+1)+,,+kC(b-1)+kCb
        long long erabi=0;
        for(int j=a;j<=min(k,b);++j)
            erabi+=nCk[k][j];
        cout<<erabi<<endl;
    }
    else{//個数がaを超えるまで取り、余りがあれば計算
        int kosu=0,saigo=0;
        long long sum=0;
        for(auto m:minuscount){
            long long val=-1*m.first;
            int num=m.second;
            if(num+kosu<=a){
                sum+=num*val;
                kosu+=num;
                if(kosu==a) break;
            }
            else{
                sum+=(a-kosu)*val;
                saigo=num;
                break;
            }
        }
        printf("%.10lf\n",(double)sum/a);
        //cout<<kosu<<" "<<saigo<<endl;
        if(kosu==a) cout<<"1"<<endl;
        else{
            int nokori=a-kosu;
            cout<<nCk[saigo][nokori]<<endl;
        }
    }
    return 0;
}