#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define LL long long

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    _for(i,0,v.size()) os << v[i] << " ";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for(typename set<T>::iterator it = v.begin();it != v.end();it++)
    os << *it <<" ";
    return os;
}

int H,W,h,w;

int main()
{
    cin >> H >> W >> h >> w;
    if(!(H%h) && !(W%w)){
        printf("No\n");
    }
    else{
        printf("Yes\n");
        if(W%w){
            vector<int> SW(W+1,0);
            for(int i = w; i <= W;i+=w){
                SW[i] = -(i/w);
            }

            for(int i = 1; i < w;i++){
                for(int j = i; j <= W;j+=w){
                    SW[j] = 505 - j;
                }
            }

            vector<int> Ws(W,0);
            _rep(i,1,W){
                Ws[i-1] = (SW[i] - SW[i-1]);
            }
            _for(i,0,H){
                _for(j,0,W){
                    if(j) printf(" ");
                    printf("%d",Ws[j]);
                }
                printf("\n");
            }

        }
        else if(H%h){
            vector<int> SH(H+1,0);

            for(int i = h; i <= H;i += h){
                SH[i] = -(i/h);
            }
            for(int i = 1; i < h;i++){
                for(int j = i; j <= H;j+=h){
                    SH[j] = 505 - j;
                }
            }
            
            vector<int> Hs(H,0);
            _rep(i,1,H){
                Hs[i-1] = (SH[i] - SH[i-1]);
            }

            _for(i,0,H){
                _for(j,0,W){
                    if(j) printf(" ");
                    printf("%d",Hs[i]);
                }
                printf("\n");
            }

        }
    }
    return 0;
}
