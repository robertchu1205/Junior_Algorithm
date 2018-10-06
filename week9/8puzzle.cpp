#include <iostream>
#include <string>
using namespace std;

void small_to_big(int a);
int main(){
    string s[3];
    for(int i=0;i<3;i++){
        cin>>s[i];
    }
    int a[3][3],f=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (s[i].compare(j*2,2,"¢°") == 0)
                a[i][j]=1;
            if (s[i].compare(j*2,2,"¢±") == 0)
                a[i][j]=2;
            if (s[i].compare(j*2,2,"¢²") == 0)
                a[i][j]=3;
            if (s[i].compare(j*2,2,"¢³") == 0)
                a[i][j]=4;
            if (s[i].compare(j*2,2,"¢´") == 0)
                a[i][j]=5;
            if (s[i].compare(j*2,2,"¢µ") == 0)
                a[i][j]=6;
            if (s[i].compare(j*2,2,"¢¶") == 0)
                a[i][j]=7;
            if (s[i].compare(j*2,2,"¢·") == 0)
                a[i][j]=8;
            if (s[i].compare(j*2,2,"¡@") == 0)
                a[i][j]=0;
        }
    }
//    for(int i=0;i<3;i++){
//        for(int j=0;j<3;j++){
//            cout<<a[i][j]<<" ";
//        }cout<<endl;
//    }
    for(int i=0;i<3;i++){//up
        for(int j=0;j<3;j++){
            if(a[i][j]==0&&i!=0){
                swap(a[i][j],a[i-1][j]);
                for(int i=0;i<3;i++){//up
                    for(int j=0;j<3;j++){
                        small_to_big(a[i][j]);
                    }cout<<endl;
                }
                if(a[0][0]!=1)
                    f++;
                if(a[0][1]!=2)
                    f++;
                if(a[0][2]!=3)
                    f++;
                if(a[1][0]!=8)
                    f++;
                if(a[1][1]!=0)
                    f++;
                if(a[1][2]!=4)
                    f++;
                if(a[2][0]!=7)
                    f++;
                if(a[2][1]!=6)
                    f++;
                if(a[2][2]!=5)
                    f++;
                cout<<f<<endl;
                f=0;
                swap(a[i][j],a[i-1][j]);
                break;
            }
        }
    }
    for(int i=0;i<3;i++){//right
        for(int j=0;j<3;j++){
            if(a[i][j]==0&&j!=2){
                swap(a[i][j],a[i][j+1]);
                for(int i=0;i<3;i++){//up
                    for(int j=0;j<3;j++){
                        small_to_big(a[i][j]);
                    }cout<<endl;
                }
                if(a[0][0]!=1)
                    f++;
                if(a[0][1]!=2)
                    f++;
                if(a[0][2]!=3)
                    f++;
                if(a[1][0]!=8)
                    f++;
                if(a[1][1]!=0)
                    f++;
                if(a[1][2]!=4)
                    f++;
                if(a[2][0]!=7)
                    f++;
                if(a[2][1]!=6)
                    f++;
                if(a[2][2]!=5)
                    f++;
                cout<<f<<endl;
                f=0;
                swap(a[i][j],a[i][j+1]);
                break;
            }
        }
    }
    for(int i=0;i<3;i++){//down
        for(int j=0;j<3;j++){
            if(a[i][j]==0&&i!=2){
                swap(a[i][j],a[i+1][j]);
                for(int i=0;i<3;i++){//up
                    for(int j=0;j<3;j++){
                        small_to_big(a[i][j]);
                    }cout<<endl;
                }
                if(a[0][0]!=1)
                    f++;
                if(a[0][1]!=2)
                    f++;
                if(a[0][2]!=3)
                    f++;
                if(a[1][0]!=8)
                    f++;
                if(a[1][1]!=0)
                    f++;
                if(a[1][2]!=4)
                    f++;
                if(a[2][0]!=7)
                    f++;
                if(a[2][1]!=6)
                    f++;
                if(a[2][2]!=5)
                    f++;
                cout<<f<<endl;
                f=0;
                swap(a[i][j],a[i+1][j]);
                break;
            }
        }
    }
    for(int i=0;i<3;i++){//left
        for(int j=0;j<3;j++){
            if(a[i][j]==0&&j!=0){
                swap(a[i][j],a[i][j-1]);
                for(int i=0;i<3;i++){//up
                    for(int j=0;j<3;j++){
                        small_to_big(a[i][j]);
                    }cout<<endl;
                }
                if(a[0][0]!=1)
                    f++;
                if(a[0][1]!=2)
                    f++;
                if(a[0][2]!=3)
                    f++;
                if(a[1][0]!=8)
                    f++;
                if(a[1][1]!=0)
                    f++;
                if(a[1][2]!=4)
                    f++;
                if(a[2][0]!=7)
                    f++;
                if(a[2][1]!=6)
                    f++;
                if(a[2][2]!=5)
                    f++;
                cout<<f<<endl;
                break;
            }
        }
    }
}
void small_to_big(int a){
    if(a==1)
        cout<<"¢°";
    if(a==2)
        cout<<"¢±";
    if(a==3)
        cout<<"¢²";
    if(a==4)
        cout<<"¢³";
    if(a==5)
        cout<<"¢´";
    if(a==6)
        cout<<"¢µ";
    if(a==7)
        cout<<"¢¶";
    if(a==8)
        cout<<"¢·";
    if(a==0)
        cout<<"¡@";
}
