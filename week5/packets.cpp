#include <iostream>
using namespace std;
int main() {
int a[6];
int u[]={0,5,3,1};
int v[]={0,11,6,5};
bool test=0;
int space1=0;
int space2=0;
int final=0;
int temp=0;
while(1)
{
    test=0;
    space1=0;
    space2=0;
    final=0;
    for(int i=0;i<6;i++) {
        cin >> a[i];
    }
    for(int i=0;i<6;i++) {
        if(a[i]!=0) {
            test=1;
            break;
        }
    }
    if(test==1) {
            final=a[5]+a[4]+a[3]+(a[2]+3)/4;
            space2=5*a[3]+u[a[2]%4];
            if(a[1]>space2) {
                final+=(a[1]-space2+8)/9;
                space1=36*final-36*a[5]-25*a[4]-16*a[3]-9*a[2];
            }
            else if (a[1]==space2) {
                space1=11*a[4];
            }
            else if(a[1]<space2) {
                space1=11*a[4]+v[a[2]%4]+4*space2;
            }
            if(a[0]>space1) {
                final=(a[0]-space1+35)/36;
            }
//        while(a[3]>0&&a[1]>4) {
//            a[3]-=1;
//            a[1]-=5;
//            final++;
//        }
//        if(a[3]!=0) {
//            final+=a[3];
//            space2+=5*a[3];
//        }
//        if(a[2]%4==0) {
//            final+=a[2]/4;
//        }
//        else if(a[2]%4==1) {
//            temp=(a[2]+3)/4;
//            final+=temp;
//            space2+=5;
//            space1+=7;
//        }
//
//        else if(a[2]%4==2) {
//            temp=(a[2]+2)/4;
//            final+=temp;
//            space2+=3;
//            space1+=6;
//        }
//
//        else if(a[2]%4==3) {
//            temp=(a[2]+1)/4;
//            final+=temp;
//            space2+=1;
//            space1+=5;
//        }
//        if(a[4]!=0) {
//            final+=a[4];
//            space1+=11*a[4];
//        }
//        if(a[5]!=0) {
//            final+=a[5];
//        }
//  //  cout << space1 << "\t" << space2 << endl;
//        if(space2==a[1]) {
//            a[1]=0;
//            space2=0;
//        }
//        else if(space2<a[1])
//            {
//                a[1]-=space2;
//                space2=0;
//            }
//        else if (space2>a[1]) {
//                space2-=a[1];
//                a[1]=0;
//                space1+=space2*4;
//        }
//        if(a[1]!=0) {
//            if(a[1]%9==0) {
//                final+=a[1]/9;
//                a[1]=0;
//            }
//            else {
//                temp=a[1]/9;
//                final+=temp+1;
//                a[1]=a[1]%9;
//                space1+=a[1]*4;
//            }
//        }
//        if(space1==a[0]) {
//            a[0]=0;
//            space1=0;
//        }
//        else if(space1>a[0]) {
//            a[0];
//        }
//        if(space1<a[0]) {
//            space1=0;
//            a[0]-=space1;
//        }
//        if(a[0]!=0) {
//            if(a[0]%36==0) {
//                final+=a[0]/36;
//            }
//            else {
//                temp=a[0]/36;
//                final+=temp+1;
//            }
//        }
//        if(a[4]!=0) {
//            if(a[0]!=0) {
//                if(a[0]<11*a[4]) {
//                    a[0]=0;
//                }
//                else {
//                    a[0]-=11*a[4];
//                }
//            }
//            final+=a[4];
//        }
    }
    else {
        break;
    }
    cout << final << endl;
}
return 0;
}
