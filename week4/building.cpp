#include <iostream>
using namespace std;
int main () {
int casenum=0;
int datanum=0;
int test=0;
int posnow;
bool end=0;
int negnow;
int output;
int output1,output2;
int posnum;
int negnum;
int pos[datanum];
int neg[datanum];
cin >> casenum;
while(casenum>0)
{
    posnum=0;
    output1=0;
    output2=0;
    negnum=0;
    cin >> datanum;
    for(int i=0;i<datanum;i++) {
        cin >> test;
        if(test<0) {
            neg[negnum]=0-test;
            negnum++;
        }
        else if(test>0) {
            pos[posnum]=test;
            posnum++;
        }
    }
    for(int i=posnum-2;i>=0;i--) {
        for(int j=0;j<=i;j++) {
            if(pos[j]>pos[j+1]) {
                swap(pos[j],pos[j+1]);
            }
        }
    }

    for(int i=negnum-2;i>=0;i--) {
        for(int j=0;j<=i;j++) {
            if(neg[j]>neg[j+1]) {
                swap(neg[j],neg[j+1]);
            }
        }
    }
//    for(int i=0;i<posnum;i++) {
//        cout << pos[i] << endl;
//    }
//    cout << "asfafasf" << endl;
//    for(int i=0;i<negnum;i++) {
//        cout << neg[i] << endl;
//    }
    output=0;
     posnow=0;
    negnow=0;
    end=0;
    if(pos[0]<neg[0]) {
        //    cout << "asdsafds" <<endl;
        output++;
        while(1) {
            while(output%2!=0) {

                  if(neg[negnow]>pos[posnow])
                  {
                      output++;
                      break;
                  }
                 negnow++;
                  if(negnow>negnum-1) {
                      cout << output <<endl;
                      end=1;
                      break;
                  }
            }
            while (output%2!=1) {
                 if(pos[posnow]>neg[negnow])
                  {
                      output++;
                      break;
                  }
                  posnow++;
                  if(posnow>posnum-1) {
                      cout << output <<endl;
                      end=1;
                      break;
                  }
            }
            if(end==1) {
                    break;
            }
        }
    }
    else if(pos[0]>neg[0]) {
        output++;
               while(1) {
            while(output%2!=0) {
                  if(neg[negnow]<pos[posnow])
                  {
                      output++;
                      break;
                  }
                  posnow++;
                  if(posnow>posnum-1) {

                      cout << output <<endl;
                      end=1;
                      break;
                  }
            }
            while (output%2!=1) {
                 if(pos[posnow]<neg[negnow])
                  {
                      output++;
                      break;
                  }
                  negnow++;
                  if(negnow>negnum-1) {
                      cout << output <<endl;
                      end=1;
                      break;
                  }
            }
            if(end==1) {
                    break;
            }
        }
    }
/*    else {
            output1++;
            output2++;
         while(1) {
            while(output1%2!=0) {

                  if(neg[negnow]>pos[posnow])
                  {
                      output1++;
                      break;
                  }
                 negnow++;
                  if(negnow>negnum-1) {
                      end=1;
                      break;
                  }
            }
            while (output1%2!=1) {
                 if(pos[posnow]>neg[negnow])
                  {
                      output1++;
                      break;
                  }
                  posnow++;
                  if(posnow>posnum-1) {
                      end=1;
                      break;
                  }
            }
            if(end==1) {
                    break;
            }
        }
        posnow=0;
        negnow=0;
        while(1) {
            while(output2%2!=0) {
                  if(neg[negnow]<pos[posnow])
                  {
                      output2++;
                      break;
                  }
                  posnow++;
                  if(posnow>posnum-1) {
                      end=1;
                      break;
                  }
            }
            while (output2%2!=1) {
                 if(pos[posnow]<neg[negnow])
                  {
                      output2++;
                      break;
                  }
                  negnow++;
                  if(negnow>negnum-1) {
                      end=1;
                      break;
                  }
            }
            if(end==1) {
                    break;
            }
        }
        if(output1>output2) {
            cout << output1 << endl;
        }
        else {
            cout << output2 << endl;
        }
    } */
    casenum--;
}
return 0;
}
