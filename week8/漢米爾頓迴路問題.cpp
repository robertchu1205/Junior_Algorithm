#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int V;
bool graph[100][100];
int path[100];

bool isSafe(int v,int path[],int pos);
bool hamCycleUtil(int path[],int pos);
bool hamCycle(int path[]);

int main(){
    int round_times;
    cin>>round_times;
    for(int j=0;j<round_times;j++){
        int edge_number;
        cin>>edge_number;
        int temp=0;
        for(int i=0;i<edge_number;i++){//cin>>(x,y)
            string s;
            cin>>s;
            int a[5],a_index=0;
            int b[5],b_index=0;
            bool turn_b=false;
            for(int i=0;i<s.length();i++){
                if(int(s[i])>=48&&int(s[i])<=57&&turn_b==false){
                    a[a_index]=s[i]-48;
                    a_index++;
                }
                if(int(s[i])==44){
                    turn_b=true;
                }
                if(int(s[i])>=48&&int(s[i])<=57&&turn_b==true){
                    b[b_index]=s[i]-48;
                    b_index++;
                }
            }
            for(int i=0;i<a_index-1;i++)
                a[i+1]+=a[i]*10;
            for(int i=0;i<b_index-1;i++)
                b[i+1]+=b[i]*10;
            graph[a[a_index-1]-1][b[b_index-1]-1]=1;
            graph[b[b_index-1]-1][a[a_index-1]-1]=1;
            temp=max(a[a_index-1],b[b_index-1]);
            V=max(V,temp);
        }
        hamCycle(path);
        for(int i=0;i<100;i++){
            for(int k=0;k<100;k++){
                graph[i][k]=0;
            }
        }
        V=0;
    }
}

bool isSafe(int v,int path[],int pos){
    if(graph[path[pos-1]][v] == 0)
        return false;
    for(int i=0;i<pos;i++)
        if(path[i]==v)
            return false;
    return true;
}
/* solve hamiltonian cycle problem */
bool hamCycleUtil(int path[],int pos){
    if(pos==V){
        if(graph[path[pos-1]][path[0]]==1)
            return true;
        else
            return false;
    }
    for(int v=1;v<V;v++){
        if(isSafe(v,path,pos)){
            path[pos]=v;
            if(hamCycleUtil(path,pos+1)==true)
                return true;
            //path[pos]=-1;
        }
    }
    return false;
}

/* solves the Hamiltonian Cycle problem using Backtracking.*/

bool hamCycle(int path[]){
    for(int i=0;i<V;i++)
        path[i]=-1;
    path[0]=0;
    if(hamCycleUtil(path,1)==false){
        cout<<"False"<<endl;
    }
    else
        cout<<"True"<<endl;
    return true;
}
