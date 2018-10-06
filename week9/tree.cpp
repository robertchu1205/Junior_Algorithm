#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 300;
bool failed;
char s[maxn];
struct Node
{
    bool have_value; //是否已建立
    int v; //值
    Node *left, *right; //left and right node
    Node():have_value(false),left(NULL),right(NULL) {}; //建構函數
};
Node *root; //root of tree

//申請新節點的函數
Node* newnode()
{
    return new Node();
}

void addnode(int v, char* s)
{
    int n = strlen(s);
    Node* u = root; // u 從根節點往下
    for(int i=0; i<n; i++)
    {
        if(s[i]=='L')
        {
            if(u->left==NULL)u->left = newnode(); //不存在則建立新節點
            u = u->left; //往左
        }
        else if(s[i]=='R')
        {
            if(u->right==NULL)u->right = newnode();
            u = u->right;
        }
    }
    if(u->have_value)failed = true;
    u->v = v;
    u->have_value = true;
}

void remove_tree(Node* u)
{
    if(u==NULL) return;
    remove_tree(u->left);
    remove_tree(u->right);
    free(u);
}






//讀取資料
bool read_input()
{
    failed = false;
    remove_tree(root);
    root = newnode(); //建立根節點
    while(1)
    {
        if(scanf("%s", s)!=1) return false;
        if(!strcmp(s,"()"))break; // End
        int v;
        sscanf(&s[1], "%d", &v); //讀入節點值(數字)
        addnode(v, strchr(s,',')+1);
    }
    return true;
}

int n=0;
vector<int> ans;
bool bfs()
{
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty())
    {
        Node* u = q.front();
        q.pop();
        if(!u->have_value) return false; //錯誤
        ans.push_back(u->v); //增加到輸出尾部
        n++;
        if(u->left != NULL)q.push(u->left);
        if(u->right != NULL)q.push(u->right);
    }
    return true;
}

int main()
{
    int num = 0;
    cin >> num;
    int i = 0;
    while(read_input() && i<num)
    {
        if(!bfs())failed=1;
        if(failed)printf("not complete\n");
        else
        {
            for(int i=0; i<ans.size()-1; i++)
            {
                printf("%d ",ans[i]);
            }
            printf("%d",ans[ans.size()-1]);
            printf("\n");
        }
        i++;
    }
    return 0;
}
