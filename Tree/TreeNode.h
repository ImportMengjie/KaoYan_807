//
// Created by mengjie on 11/22/18.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <string>
#include <iostream>


struct TreeNode {
    char data;
    TreeNode *lChild;
    TreeNode *rChild;
};

void CreateTree(TreeNode *&tree, std::string &data) {
    if (data[0] == '#' || data.empty())
        tree = NULL;
    else {
        tree = new TreeNode();
        tree->data = data.data()[0];
        data = data.substr(1, data.length());
        CreateTree(tree->lChild, data);
        data = data.substr(1, data.length());
        CreateTree(tree->rChild, data);
    }
}

void printTree(TreeNode *tree, int space = 0) {
    if (tree) {
        printTree(tree->rChild, 1 + space);
        for (int a = 0; a < space; a++)
            printf("  ");
        printf("%c\n", tree->data);
        printTree(tree->lChild, 1 + space);
    }
}

void InOrder(TreeNode *tree) {
    if (tree == NULL)
        return;
    else {
        InOrder(tree->lChild);
        std::cout << tree->data << '\t';
        InOrder(tree->rChild);
    }
}

void PreOrder(TreeNode *tree) {

    if (tree == NULL)
        return;
    else {
        std::cout << tree->data << '\t';
        PreOrder(tree->lChild);
        PreOrder(tree->rChild);
    }
}

void PostOrder(TreeNode *tree) {
    if (tree == NULL)
        return;
    else {
        PostOrder(tree->lChild);
        PostOrder(tree->rChild);
        std::cout << tree->data << '\t';
    }
}

#endif //TREE_TREE_H
