#include <bits/stdc++.h>
using namespace std;

//関数
void Eerase(vector<set<long>> &path,long a,long b){//二つの頂点が繋がってたら消す。
    set<long>::iterator ite2;;
    ite2=path.at(a).find(b);
    if(ite2!=path.at(a).end()){
        path.at(a).erase(b);
    }
    ite2=path.at(b).find(a);
    if(ite2!=path.at(b).end()){
        path.at(b).erase(a);
    }
}

void Verase(vector<set<long>> &path,long a){//一つの頂点を全消し
    set<long>::iterator ite3;;
    while(path.at(a).size()>0){
        ite3=path.at(a).begin();
        Eerase(path,a,*ite3);
    }
}

    
//main関数
int main() {
    
    
    //入力
    long N,M;
    cin>>N>>M;
    vector<long> A(M),B(M);
    for(int i=0;i<M;i++){
        cin>>A.at(i)>>B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    
    
    
    //計算
    vector<set<long>> path(N, set<long>());
    for(int i=0;i<M;i++){
        path.at(A.at(i)).insert(B.at(i));
        path.at(B.at(i)).insert(A.at(i));
    }
    
    set<long>::iterator ite;;
    
    vector<long> ansr(M),ansl(M);//>>答えの長さ
    long lengthr=1,lengthl=1;
    ansr.at(0)=0;
    ite=path.at(0).begin();//1つ目をとる
    ansl.at(0)=*ite;
    Eerase(path,ansr.at(0),ansl.at(0));//繋がってたら消す。
    
    bool ryet=(path.at(ansr.at(0)).size()>0),lyet=(path.at(ansl.at(0)).size()>0);
    
    
    while(ryet || lyet){
        if(ryet){
            lengthr++;
            ite=path.at(ansr.at(lengthr-2)).begin();
            ansr.at(lengthr-1)=*ite;
            Verase(path,ansr.at(lengthr-2));
            Eerase(path,ansr.at(lengthr-1),ansl.at(lengthl-1));
            //display(path,N);
        }
        
        ryet=(path.at(ansr.at(lengthr-1)).size()>0);
        lyet=(path.at(ansl.at(lengthl-1)).size()>0);
        if(lyet){
            lengthl++;
            ite=path.at(ansl.at(lengthl-2)).begin();
            ansl.at(lengthl-1)=*ite;
            Verase(path,ansl.at(lengthl-2));
            Eerase(path,ansr.at(lengthr-1),ansl.at(lengthl-1));
            //display(path,N);
        }
        
        ryet=(path.at(ansr.at(lengthr-1)).size()>0);
        lyet=(path.at(ansl.at(lengthl-1)).size()>0);
      //display(path,N);
    }
    
    //出力
    cout<<lengthr+lengthl<<endl;
    for(int i=lengthr-1;i>0;i--){
        cout<<ansr.at(i)+1<<" ";
    }
    cout<<1;
    for(int i=0;i<lengthl;i++){
        cout<<" "<<ansl.at(i)+1;
    }
    cout<<endl;
}