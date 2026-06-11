


#include<vector>
#include<map>
#include<iostream>
using namespace std;

#define MOD (1000000007)

pair<int, int> pl(int a , int N){
    int mp = N/2;
    return make_pair(mp -a/2 , mp + a/2);
}

int main(){
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i=0; i<N; i++){
        int a;
        cin >> a;
        //printf("a %d \n",a);
        pair<int, int> pr = pl(a, N);
        bool single_point = (pr.first == pr.second);
        //printf("a %d , %d, %d\n",a , pr.first, pr.second);
        // cout << "MP" << endl;
        // for(auto x: mp){
        //     cout << x.first << ", " << x.second << endl;
        // }
        // cout << "/MP" << endl;
        if(!mp.count(a)){
            mp[a]=1;
        } else {
            auto it = mp.find(a);
            // printf("a %d, it %d, %d\n",a, it->first, it->second);
            if ((single_point && N%2==1) || (!single_point && it->second>2)){
                printf("0\n"); // single point duplicated or two people must be in same spot
                return 0;
            }
            mp[a]+=1;
        }
            
    }

    long long sol = 1;
    for(map<int,int>::iterator it = mp.begin(); it!=mp.end(); it++){
        if(it->second==2){
            sol <<=1;
            sol%=MOD;
        }
    }
    printf("%llu\n", sol);

}