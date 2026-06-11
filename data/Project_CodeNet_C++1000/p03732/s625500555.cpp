#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N, W;
    cin >> N >> W;
    long w0, weight, value;
    long v[4][N];
    int count[4]={};
    long val[4]={};
    long wtmp, vtmp, ans;

    for(int i=0; i<N; i++){
        int ii=0;
        if(i==0){
            count[ii]++;
            cin >> w0 >> v[i][count[ii]-1];
        }else{
            cin >> wtmp >> vtmp;
            ii=wtmp-w0;
            count[ii]++;
            v[ii][count[ii]-1]=vtmp;
        }
    }

    for(int i=0; i<4; i++){
        sort( v[i],v[i]+count[i] );
    }
    for(int i=0; i<4; i++){
        for(int j=0; j< (int) count[i]/2; j++){
            swap(v[i][j],v[i][count[i]-1-j]);
        }
    }

    //cout << "count " << count[0] << " " << count[1] << " " << count[2] << " " << count[3] << endl;

    ans=0;
    weight=0;
    value=0;
    for( int i=-1; i<count[0]; i++ ){
        if(i!=-1){
            val[0]+=v[0][i];
        }
        for(int j=-1; j<count[1]; j++){
            if(j!=-1){
                val[1]+=v[1][j];
            }
            for(int k=-1; k<count[2]; k++){
                if(k!=-1){
                    val[2]+=v[2][k];
                }
                for(int l=-1; l<count[3]; l++){
                    if(l!=-1){
                        val[3]+=v[3][l];
                    }
                    weight = w0*(i+1) + (w0+1)*(j+1) + (w0+2)*(k+1) + (w0+3)*(l+1);
                    value = val[0]+val[1]+val[2]+val[3];
                    //cout << "i j k l weight value " << i+1 << " " << j+1 << " " << k+1 << " " << l+1 << " " << weight << " " << value << endl;
                    if( weight <= W && value > ans ){ 
                        ans=value;
                    } 
                }
                val[3]=0;
            }
            val[2]=0;
        }
        val[1]=0;
    }

    cout << ans << endl;

    return 0;
}