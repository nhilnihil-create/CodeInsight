#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

int N=105;

char inter(string s){
    LL n = stol(s);
    if(N<=n&&to_string(N)<=to_string(n))return 'Y';
    if(N>n&&to_string(N)>to_string(n))return 'Y';
    return 'N';
}

bool ask(string s){
    cout<<"? "<<s<<endl;
    cout.flush();
    char res;cin>>res;
    return (res=='Y');
}

void ans(string s){
    cout<<"! "<<s<<endl;
    cout.flush();
}

int main(){

    string num="";
    while(true){
        int left=-1,right=9;
        while(true){
            //YESならそれ以下、NOならそれより大きい
            int center=(left+right)/2;
            if(num.size()==0&&center==0){
                num="1";
                break;
            }
            string nine="";
            REP(i,17-num.size())nine+="9";
            if(!ask(num + to_string(center)+nine))left=center;
            else{
                if(center==0){
                    //0でYの場合
                    string _s =to_string(stoi(num)*10-1);
                    if(!ask(_s)^_s.size()==num.size()){
                        ans(num);
                        return 0;
                    }
                }
                right =center;
            }
            if(center==(left+right)/2){
                num+=to_string(right);
                break;
            }
        }
    }

}