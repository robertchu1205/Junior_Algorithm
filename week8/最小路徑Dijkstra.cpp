#include<iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int stage_number;
    cin>>stage_number;

    int d[26]={},d_number=0,w[26][26]={};
    for(int i=0;i<stage_number;i++){
        string str;
        cin>>str;
        d_number+=str.length();
    }
    for(int i=1;i<d_number;i++){
        d[i]=9999;
    }
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<d_number;i++){
        pq.push(i);
    }
    int edge_number;
    cin>>edge_number;
    for(int i=0;i<edge_number;i++){
        string str;
        cin>>str;
        int weight=0;
        if(int(str[0])>=49&&int(str[0])<=57){//input number
                str[0]+=16;
                str[1]+=16;
        }
        for(int j=3;j<str.length()-1;j++){
            weight+=(int(str[j])-48)*10;
        }
        weight+=int(str[str.length()-1])-48;
        w[ int(str[0])-65 ][ int(str[1])-65 ]=weight;
        w[ int(str[1])-65 ][ int(str[0])-65 ]=w[ int(str[0])-65 ][ int(str[1])-65 ];
    }
    while(!pq.empty()) {
        int u=pq.top();
        for(int i=0;i<d_number;i++){
            if(i!=u&&w[u][i]>0&&d[i]>d[u]+w[u][i]){
                d[i]=d[u]+w[u][i];
            }
        }
        pq.pop();                    // Remmove highest priority string
    }
    cout<<d[d_number-1];
}
