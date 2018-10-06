#include <iostream>
#include <math.h>
using namespace std;
float code[10]={0};
int main() {
string s;
cin >> s;
int test;
int ele_count=0;    //字母總個數
int count_count=0;  //字母頻率個數
int num=s.length();
char input[num];    //輸入字串存成字元
char ele[10];       //字母
int count[10]={0};  //該字母頻率
 for(int i=0; i<num; i++){
          input[i] = s[i];
 }
//  for(int i=0; i<num; i++){
//          cout << input[i] << endl;
// }
 test=0;
 int x=0;
 while(num!=x) {
    if(input[test]=='\0')
    {
        test++;
    }
    else {
    ele[ele_count]=input[test];
    ele_count++;
    count[count_count]++;
    x++;
    for(int i=num-1;i>test;i--) {
        if(input[i]==input[test]) {
            x++;
            input[i]='\0';
            count[count_count]++;
        }
    }
    input[test]='\0';
    test++;
    count_count++;
    }
 }
bool judge_swap=0;
for(int i=ele_count-1;i>=0;i--) {
        judge_swap=0;
    for(int j=0;j<i;j++) {
        if(count[j]>count[j+1]) {
            swap(count[j],count[j+1]);
            swap(ele[j],ele[j+1]);
            judge_swap=1;
        }
    }

        if(judge_swap==0) {
            break;
        }
}
//for(int i=0;i<ele_count;i++) {
//    cout << ele[i] << " : " << count[i] << endl;
//}
//for(int i=0;i<ele_count;i++) {
//    cout << ele[i] << ":" << code[i] << endl;
//}
int add=count[0];
float add_count[]={1,1,1,1,1,1,1,1,1,1};
for(int i=1;i<ele_count;i++) {
        if(count[i]>add) {
            add+=count[i];
            code[i]+=add_count[i];
            for(int j=i;j>=0;j--) {
                add_count[j]*=10;
            }

        }
        else {
            add+=count[i];
            for(int x=i-1;x>=0;x--) {
                    code[x]+=add_count[x];
                    add_count[x]*=10;
            }
            add_count[i]*=10;
        }
}
bool judge_swap2=0;
for(int i=ele_count-1;i>=0;i--) {
        judge_swap2=0;
    for(int j=0;j<i;j++) {
        if(code[j]>code[j+1]) {
            swap(code[j],code[j+1]);
            swap(ele[j],ele[j+1]);
            judge_swap2=1;
        }
    }

        if(judge_swap2==0) {
            break;
        }
}
for(int i=0;i<ele_count;i++) {
    cout << ele[i] << ":" << code[i];
    if(i!=ele_count-1) {
        cout << endl;
    }
}
return 0;
}
