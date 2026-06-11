#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int bin_search(int l, int r, vector<vector<int> > &A){
    int mid=(l+r)/2+(l+r)%2;
    if(mid==r){
        return mid;
    }
    int N=A.size();
    int M=A[0].size();
    
    vector<int> index(N,0);
    vector<int> no(M,0);
    int flag=0;
    while(flag==0){
        vector<int> cnt(M,0);
        for(int i=0; i<N; i++){
            int j=index[i];

            while(j<M && no[A[i][j]]==1){
                index[i]++;
                j++;
            }
            if(j==M){
                return bin_search(mid, r, A);
            }

            int a=A[i][j];
            cnt[a]++;
        }

        flag=1;
        for(int i=0; i<M; i++){
            if(cnt[i]>mid){
                no[i]=1;
                flag=0;
            }
        }
        //cout << mid << ' ' << flag << endl;
        //cout_vec(cnt);
    }
    //cout << mid << endl;
    //cout_vec(no);

    if(flag==1){
        return bin_search(l, mid, A);
    }else{
        return bin_search(mid, r, A);
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int> > A(N,vector<int>(M,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int a;
            cin >> a;
            A[i][j]=a-1;
        }
    }

    cout << bin_search(0, N, A) << endl;
}