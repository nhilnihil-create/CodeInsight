#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int N,W;
    cin >> N >> W;
    ll w[N];
    ll v[N];
    for(int i=0;i<N;i++){
        cin >> w[i] >> v[i];
    }
    vector<ll> w1,w2,w3,w4;
    for(int i=0;i<N;i++){
        if(w[i]==w[0]){
            w1.push_back(v[i]);
        }else if(w[i]==w[0]+1){
            w2.push_back(v[i]);
        }else if(w[i]==w[0]+2){
            w3.push_back(v[i]);
        }else{
            w4.push_back(v[i]);
        }
    }
    sort(w1.begin(),w1.end(),greater<ll>());
    sort(w2.begin(),w2.end(),greater<ll>());
    sort(w3.begin(),w3.end(),greater<ll>());
    sort(w4.begin(),w4.end(),greater<ll>());
    w1.insert(w1.begin(),0);
    w2.insert(w2.begin(),0);
    w3.insert(w3.begin(),0);
    w4.insert(w4.begin(),0);
    //for(int i=0;i<w1.size();i++){
        //cout << w1[i] << endl;
    //}
    for(int i=1;i<w1.size();i++){
        w1[i]+=w1[i-1];
    }
    for(int i=1;i<w2.size();i++){
        w2[i]+=w2[i-1];
    }
    for(int i=1;i<w3.size();i++){
        w3[i]+=w3[i-1];
    }
    for(int i=1;i<w4.size();i++){
        w4[i]+=w4[i-1];
    }
    ll ans=0;
    for(int i=0;i<w1.size();i++){
        for(int j=0;j<w2.size();j++){
            for(int k=0;k<w3.size();k++){
                for(int l=0;l<w4.size();l++){
                    ll weight=i*w[0]+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3);
                    if(weight<=W){
                        ll sum=w1[i]+w2[j]+w3[k]+w4[l];
                        ans=max(ans,sum);
                    }
                }
            }
        }
    }
    std::cout << ans << endl;
}