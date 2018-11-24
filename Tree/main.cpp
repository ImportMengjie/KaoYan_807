#include <iostream>
#include "TreeNode.h"
#include <string>

using namespace std;

int main() {
    TreeNode *ptree=new TreeNode();
    string data = "ABC##D#F##EG###";
    CreateTree(ptree, data);
    printTree(ptree);
    cout<<"InOrder:";
    InOrder(ptree);
    cout<<"\nPreOrder:";
    PreOrder(ptree);
    cout<<"\nPostOrder:";
    PostOrder(ptree);
    cout<<"\nPreOrder2:";
    PreOrder2(ptree);

    return 0;
}