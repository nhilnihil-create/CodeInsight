#include<iostream>
using namespace std;

long long ways[51][51][2501] = {0};

int main(){
    int N, A;
    cin >> N >> A;
    int x[N];
    for(int i=0; i<N; i++){
        cin >> x[i];
    }

    ways[0][0][0]=1;

    for(int beforePos=1; beforePos<=N; beforePos++){
        for(int chooseNum=beforePos; chooseNum>=0; chooseNum--){
            for(int value=A*N+1; value>=0; value--){
                ways[beforePos][chooseNum][value]+=ways[beforePos-1][chooseNum][value];
                if(value>=x[beforePos-1] && chooseNum>=1){
                    ways[beforePos][chooseNum][value]+=ways[beforePos-1][chooseNum-1][value-x[beforePos-1]];
                }
            }
        }
    }

    long long totalWays=0;

    for(int chooseNum=1; chooseNum<=N; chooseNum++){
        totalWays += ways[N][chooseNum][chooseNum*A];
    }

    cout << totalWays << '\n';
}
