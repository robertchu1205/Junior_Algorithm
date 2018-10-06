#include <iostream>
using namespace std;
int main() {
int casenum;
int scorenum;
int Anum=1;
int Bnum=1;
bool change=0;
int temp;
int tempbefore;
int Anow;
int Bnow;
int output;
int a[Anum];
int b[Bnum];
cin >> casenum;
while(casenum>0) {
    output=0;
    Anow=0;
    Bnow=0;
    temp=0;
    tempbefore=0;
    Anum=0;
    Bnum=0;
    change=0;
    cin >> scorenum;
    for(int i=0;i<scorenum;i++) {
        cin >> temp;
        if(i==0) {
            a[0]=temp;
            tempbefore=a[0];
            Anum++;
        }
        if(change==0) {
            if(temp>tempbefore) {
                a[Anum]=temp;
                tempbefore=a[Anum];
                Anum++;
            }
            else if(temp<tempbefore) {
                change=1;
                b[Bnum]=temp;
              //  tempbefore=b[Bnum];
                Bnum++;
            }
        }
        else {
            b[Bnum]=temp;
            Bnum++;
        }
    }
    while(output<3){
            if(Anow<Anum&&Bnow<Bnum) {
        if(b[Bnow]<a[Anow])
        {
           cout << "B";
           Bnow++;
        }
        else if(b[Bnow]>a[Anow]){
            cout << "A";
            Anow++;
        }
            }
            else if(Anow==Anum) {
                cout << "B";
                Bnow++;
            }
            else if(Bnow==Bnum) {
                cout << "A";
                Anow++;
            }
        output++;
    }
    cout << endl;
//
//    for(int i=0;i<Anum;i++) {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//
//    for(int i=0;i<Bnum;i++) {
//        cout << b[i] << " ";
//    }
//    cout << endl;
    casenum--;
}
return 0;
}
