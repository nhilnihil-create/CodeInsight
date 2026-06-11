#include<bits/stdc++.h>
#define rep(i,e,n) for(int i=e; i<n; i++)

using namespace std;

int main()
{
    int W , H , N;
    cin >> W >> H >> N;

    vector<vector<bool>> b(H,vector<bool>(W));

    for(int i=0; i<N; i++){
        int x,y,a;
        cin >> x >> y >> a;

        if(a == 1){
            rep(h,0,H){
                rep(w,0,x){
                    b.at(h).at(w) = true;
                }
            }
        }
        if(a == 2){
            rep(h,0,H){
                rep(w,x,W){
                    b.at(h).at(w) = true;
                }
            }  
        }
        if(a == 3){
            rep(h,0,y){
                rep(w,0,W){
                    b.at(h).at(w) = true;
                }
            }
        }
        if(a == 4){
            rep(h,y,H){
                rep(w,0,W){
                    b.at(h).at(w) = true;
                }
            }
        }    
    }

    int cnt=0;
    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            if(b.at(h).at(w) == false)
            cnt++;
        }
    }

    cout << cnt << endl;
}