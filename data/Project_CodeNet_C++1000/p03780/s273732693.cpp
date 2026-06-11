//ヘッダー
#include<bits/stdc++.h>
using namespace std;


//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define REP2(i,a,b) for(int i=a;i<(int)(b);i++)
#define REPD2(i,a,b) for(int i=a;i>(int)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((int)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

bool L[5010][5010];
bool R[5010][5010];
int sumr[5010][5010];


int main(){
    int N,K;
    cin>>N>>K;
    vector<int> a(N);
    
    REP(i,N) cin>>a[i];
    sort(ALL(a));
    REP(i,5010){
        REP(j,5010){
            if(j==0){
                L[i][j]=true;
                R[i][j]=true;
            }else{
                L[i][j]=false;
                R[i][j]=false;
            }
        }
    }
    REP(i,N){
        REP(j,5010){
            if(a[i]>=K) continue;
            if(j-a[i]>=0){
                L[i+1][j]=L[i][j-a[i]]|L[i][j];
            }else{
                L[i+1][j]=L[i][j];
            }
        }
    }

    sort(ALL(a),greater<int>());
    REP(i,N){
        REP(j,5010){
            if(a[i]>=K) continue;
            if(j-a[i]>=0){
                R[N-1-i][j]=R[N-i][j-a[i]]|R[N-i][j];
            }else{
                R[N-1-i][j]=R[N-i][j];
            }
        }
    }


    sort(ALL(a));

    int ans=0;
    
    REP(i,5010){
        REP(j,5010){
            sumr[i][j]=0;
        }
    }

    REP(i,5010){
        REP(j,5009){
            sumr[i][j+1]=sumr[i][j]+R[i][j];
        }
    }

    REP(i,N){
        if(a[i]>=K) continue;
        bool flag=true;
        REP(j,K+1){
            if(!L[i][j]) continue;
            int l=max(K-a[i]-j,0);
            int r=K-j;
            if(sumr[i+1][r]-sumr[i+1][l]>0){
                flag=false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout<<ans<<endl;


}