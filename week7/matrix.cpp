#include <iostream>
#include <cstdlib>
using namespace std;
int top=0;
char now='.';
int nowarr[100][2];
int nowindex=0;
char arr[100];
        void push(char item) {
            arr[top]=item;
            top++;
        }
        char pop() {
            if(top==0) {
                cout << "no items in stack" << endl;
            }
            else {
                top--;
                return arr[top];
            }
        }
void howbig(int n,string s,char *c,int (*m)[2])
{
    bool test=true;
   int sum=0;
   int num;
   char a,b;
   int a_index=0;
   int b_index=0;
   num=s.size();
   for(int i=0;i<num;i++) {
        if(num==1) {
            cout << "0" << endl;
            test=false;
            break;
        }
        if(s[i]==')') {
            //    cout << "afasf";
            a_index=0;
            b_index=0;
            b=pop();
            a=pop();
            pop();
      //      cout << a << " " << b << endl;
            if(a==now&&b!=now) {
                while(b!=c[b_index]) {
                    b_index++;
                }
                if(nowarr[nowindex][1]!=m[b_index][0]) {
                    cout << "error" << endl;
                    test=false;
                    break;
                }
                else {

                    sum+=nowarr[nowindex][0]*nowarr[nowindex][1]*m[b_index][1];
                    nowarr[nowindex][1]=m[b_index][1];
                    nowarr[nowindex][0]=nowarr[nowindex][0];
                    push(now);
                }
            }
            else if(b==now&&a!=now) {
                 while(a!=c[a_index]) {
                    a_index++;
                }
                 if(m[a_index][1]!=nowarr[nowindex][0]) {
                    cout << "error" << endl;
                    test=false;
                    break;
                }
                else {
                    sum+=m[a_index][0]*m[a_index][1]*nowarr[nowindex][1];
                    nowarr[nowindex][0]=m[a_index][0];
                    nowarr[nowindex][1]=nowarr[nowindex][1];
                    push(now);
                }
            }
            else if(a==now&&b==now) {
                  //  cout << "asdsf";
                   // cout << nowarr[nowindex-1][0] << " " << nowarr[nowindex-1][1] << endl;
                   // cout << nowarr[nowindex][0] << " " << nowarr[nowindex][1] << endl;
                   if(nowarr[nowindex-1][1]!=nowarr[nowindex][0]) {
                    cout << "error" << endl;
                    test=false;
                    break;
                }
                else {
                    sum+=nowarr[nowindex-1][0]*nowarr[nowindex][0]*nowarr[nowindex][1];
                    nowarr[nowindex][0]=nowarr[nowindex-1][0];
                    nowarr[nowindex][1]=nowarr[nowindex][1];
                    push(now);
                }
            }
            else {
                while(a!=c[a_index]) {
                    a_index++;
                }
                while(b!=c[b_index]) {
                    b_index++;
                }
                if(m[a_index][1]!=m[b_index][0]) {
                    cout << "error" << endl;
                    test=false;
                    break;
                }
                else {
                    nowarr[nowindex][0]=m[a_index][0];
                    nowarr[nowindex][1]=m[b_index][1];
                    push(now);
                    sum+=m[a_index][0]*m[a_index][1]*m[b_index][1];
                }
            }
            if(s[i+1]=='(') {
                    nowindex++;
               }
        }
        else if(s[i]=='(') {
              push(s[i]);
        }
        else if(s[i]!=')'&&s[i]!='(') {
            push(s[i]);
        }
   }
   if(test==true) {
   cout << sum <<endl;
   }
}
int main() {
int datanum;
cin >> datanum;
char voc[datanum];
int ma[datanum][2];
for(int i=0;i<datanum;i++) {
    cin >> voc[i];
    cin >> ma[i][0] >> ma[i][1];
}
string s_input;
while(cin >> s_input) {
    howbig(datanum,s_input,voc,ma);
}
return 0;
}
