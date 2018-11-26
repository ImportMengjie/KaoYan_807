# DataStructure_807

## （一）绪论

### 数据结构的基本概念，数据的逻辑结构、存储结构；

#### 逻辑结构:
1. 线性结构
2. 非线性结构
    - 树
    - 图
    - 集合

#### 存储结构

1. 顺序存储
2. 链接存储
3. 索引存储
    - 在存储的同时,还建立附加的索引表
4. 散列存储

### 算法的定义和应具有的特性，算法设计的要求，算法的时间复杂度分析和算法的空间复杂度分析。
 
## （二）线性表
 
### 线性结构的特点、线性表的定义，线性表的基本操作；

[list定义](./List/List.h)

线性表的顺序存**储**结构是一种*随机存**取***的存储结构,线性表的链式存储结构是一种*顺序存**取***的存储结构.

### 线性表的顺序存储结构，对其进行检索、插入和删除等操作；
 
### 线性表的链式存储结构，单链表、双向链表和循环链表这三种链表形式的存储结构和特点以及基本操作。
 
## （三）栈和队列，递归算法
 
### 栈的定义、结构特点及其存储方式(顺序存储与链接存储)和基本操作的实现算法；
 
### 队列的结构、特点及其存储方式(顺序存储与链接存储)和基本操作的实现算法。
[循环队列实现](./List/CircularQueue.h)

```c
// 初始化
Q.rear=Q.front=0;

// 判断空
Q.rear==Q.front;

// 判断队满
(Q.rear+1)%MAXSIZE==Q.front;

// 队列长度
(Q.rear+MAXSIZE-Q.front)%MAXSIZE;

```
 
### 递归的基本概念和实现原理以及用递归的思想描述问题和书写算法的方法；
 
### 用栈实现递归问题的非递归解法。
 
## （四）数组和串
 
### 串的基本概念、串的存储结构和相关的操作算法；
 
### 数组的存储结构，在顺序存储的情况下，数组元素与存储单元的对应关系；
 
### 稀疏矩阵的存储结构和特点以及基本操作。
    对于矩阵中实际存储的元素<<矩阵大小时,可以只存取三元组(行标,列标,值)的list.
 
### 字符串匹配算法(例如KMP算法)。
 
## （五）树和森林
 
### 树的结构和主要概念，各种二叉树的结构及其特点；

#### 树的基本术语

1. 度  

    树中一个节点的子节点个数称为该**节点的度**,树中最大度数称为**树的度**

2. 深度 

    从根节点开始自顶向下逐层累加

3. 高度 
   
   从叶节点开始自底向上逐层累加

4. 树的高度(深度) 

   树中节点最大的层数

#### 二叉树的特点

N<sub>0</sub>表示叶子节点数,N<sub>2</sub>表示度为2的节点则N<sub>0</sub>=N<sub>2</sub>+1

故在有N个节点的二叉树中,有N+1个空指针;空指针数 = 2*N<sub>0</sub>+N<sub>1</sub>=N<sub>0</sub>+N<sub>1</sub>+N<sub>2</sub>+1

#### 二叉树的数组表示方法

If a complete binary tree with n nodes is represented sequentially, then for any node with index i, $1 \leq i \leq n$, we have

1. parent(i) is at int(i/2) if $i \neq 1$. If i = 1, i is at the root and has no parent.
2. LeftChild(i) is at 2i if $2i \leq n$. If $2i \geq n$, then i has no left child.
3. RightChild(i) is at 2i+1 if $2i+1 \leq n$. If $2i+1 \geq n$, then i has no right child.


##### 二叉树与度为2的树的区别

1. 度为2的树至少含有三个节点才可以,二叉树则可为空
2. 度为2的树如果某个节点只有一个孩子节点则无需分左右,而二叉树不同 

#### 各种二叉树

1. 满二叉树
    
    叶子节点都在二叉树的最下一层,并且除叶节点之外的每个节点的度数都为2

2. 完全二叉树 

    每个节点都与高度一样的满二叉树编号一一对应.也就是只有最下一层的右边可以缺少元素.

3. 平衡二叉树

    树上任意节点的左子树和右子树的深度之差不超过1
 
### 二叉树的三种遍历方法的实现原理和性质，能将二叉树的遍历方法应用于求解二叉树的叶子结点个数、二叉树计数等问题，遍历的非递归实现方法；

#### 遍历方法

1. 先序遍历(PreOrder)

    顺序:根节点,先序遍历左子树,先序遍历右子树

    实现: [递归实现](./Tree/TreeNode.h#L51)

    非递归实现

    ```c
    void PreOrder2(BiTree t){
        InitStack(S);
        BiTree p = t;
        while(p||!IsEmpty(S)){
            if(p){
                visit(p);
                Push(S,p);
                p = p->lchild;
            }
            else{
                Pop(S,p);
                p=p->rchild;
            }
        }
    }
    ```

2. 中序遍历(InOrder)

    顺序:中序遍历左子树,根节点,中序遍历右子树

    实现: [递归实现](./Tree/TreeNode.h#L41)

    非递归实现

    ```c
    void InOrder2(BiTree t){
        InitStack(S);
        BiTree p = t;
        while(p||!IsEmpty(S)){
            if(p){
                Push(S,p);
                p = p->lchild;
            }
            else{
                Pop(S,p);
                visit(p);
                p=p->rchild;
            }
        }
    }
    ```

3. 后序遍历(PostOrder)

    顺序:后序遍历左子树,后序遍历右子树,根节点
    
    实现: [递归实现](./Tree/TreeNode.h#L62)

    非递归实现:

    ```c
    void PostOrder(BiTree T){
        InitStack(S);
        BiTree p = T;
        BiTree r = NULL:
        while(p||!IsEmpty(S)){
            if(p){
                push(S,p);
                p = p->lchild;
            }
            else{
                GetTop(S,p);
                if(p->rchild&&p->rchild!=r){
                    p=p->rchild;
                    push(S,p);
                    p=p->lchild;
                }
                else{
                    pop(S,p);
                    visit(p->data);
                    r=p;
                    p=NULL;
                }
            }
        }
    }
    ````


根据先序遍历和中序遍历或后序遍历和中序遍历可以确定一颗二叉树,而**先序和后序则不能确定一颗二叉树**

#### 层次遍历

```c
void LevelOrder(BiTree T){
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while (!IsEmpty(Q)){
        Dequeue(Q,p);
        visit(p);
        if(p->lchild!=NULL){
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){
            EnQueue(Q,p->rchild);
        }
    }
}
```

#### 计算树的深度

```c
int BitDepth(BiTree T){
    if (T==NULL) 
        return 0;
    else{
        ldep = Btdepth(T->lchild);
        rdep = Btdepth(T->rchild);
        if(ldep>rdep)
            return ldep+1;
        else
            return rdep+1;
    }

}
```
 
### 线索化二叉树的结构和基本操作；

格式:

| ltag| lchild|data|rchild|rtag|
|:----:|:----:|:----:|:----:|:----:|
| 1:指向节点的前驱| | | | 1:指向节点的后继|
 
### 森林的定义和存储结构，森林的遍历等方法的实现；

#### 森林存储结构

1. 双亲表示法

    ![双亲表示法](images/森林双亲表示法.png)

2. 孩子表示法

    ![孩子表示法](images/孩子表示法.png)

3. 孩子兄弟表示法

    ![孩子兄弟表示法](images/孩子兄弟表示法.png)

#### 森林=>二叉树

用孩子兄弟表示法将树=>二叉树(由于根节点没有兄弟所以没有右子树)=>将森林的多颗树连在一起

例:

![森林=>二叉树](images/森林转二叉树例子.png)

#### 森林遍历方法

树和森林遍历与二叉树遍历的对应关系

|树|森林|二叉树(将森林或树转换成的二叉树)|
|:----:|:---:|:----:|
|先根遍历|先序遍历|先序遍历|
|后根遍历|中序遍历|中序遍历|

### 基于霍夫曼树生成霍夫曼编码的方法；

![huffman](images/huffman1.bmp)
![huffman](images/huffman2.bmp)

### AVL树的定义和特点以及AVL树调整操作的实现原理；

#### AVL树的定义

节点的平衡因子是它的左子树的高度减去它的右子树的高度（有时相反）。带有平衡因子1、0或 -1的节点被认为是平衡的。

#### 调整操作

1. LR型

    ![LR](images/AVLtree_LR.png)

2. LL型

    ![LL](images/AVLtree_LL.png)

3. RR型

    ![RR](images/AVLtree_RR.png)

4. RL型

    ![RL](images/AVLtree_RL.png)

### 最优二叉树的构造原理和相关算法。

```c
treenode *huffmanTree(int n) {  //n为叶子个数
    int index = 0;        
    for (int i = 0; i < n; ++i) {  //将每一个叶子节点建成一棵树，放入数组tree[]中
        treenode *p = new treenode;
        p->data = arr[i];   //arr[]中放着叶子节点的权值
        p->lch = NULL;
        p->rch = NULL;
        tree[index++] = p;
    }
    treenode *root = NULL;   //定义最优二叉树的根
    for (int i = 0; i < n - 1; ++i) { //每次取arr[]中未使用的最小两个值
        sort(arr + i, arr + n);
        treenode *ch1 = NULL, *ch2 = NULL;
        for (int j = 0; j < index; ++j) {//在数组tree[]中找到这两个值，建立新的节点
            if(tree[j]->data == arr[i])
                ch1 = tree[j];
            if(tree[j]->data == arr[i + 1])
                ch2 = tree[j];
            if(ch1 && ch2) break;
        }
        treenode *p = new treenode;//建立新的节点，存入数组tree[]中
        p->data = ch1->data + ch2->data;
        p->lch = ch1;
        p->rch = ch2;
        root = p;//更新根，直到建立完成
        tree[index++] = p;
        arr[i + 1] = p->data;//并将这个节点的权值传入数组arr[]中
    }
    return root;
}

```

## （六）图

### 图的各种基本概念和各种存储方式；

#### 图的基本概念

1. 有向图

    ![有向图](/images/有向图.png)

    表示法:

    V(G3)={0,1,2} 

    E(G3)={<0,1>,<1,0>,<1,2>}

    强连通: 节点v到w和w到v都有**路径**

    强连通分量: 极大强连通子图

    入度,出度: 入度和=出度和=边数

2. 无向图

    ![无向图](/images/无向图.png)

    表示法

    V(G1)={0,1,2,3}

    E(G1)={(0,1),(0,2),(0,3),(1,2),(1,3),(2,3)}

    连通: 从v到w的**路径**存在,则v和w是连通的.

    连通图: 图G的任意两个顶点都是连通的.

    连通分量: 极大连通子图; 连通图只有一个连通分量; 非连通图有多个连通分量

    极大连通子图: 要求连通子图包含其所有的边

    极小连通子图: 保持连通又使得边数最少(生成树)

3. 完全图

    任意两个顶点都存在边.

    - n个顶点的有向图=>n(n-1)条边
    - n个顶点的无向图=>n(n-1)/2条边

4. 稀疏图|E|<|V|*log|V|和稠密图

#### 各种存储方式

1. 邻接矩阵法

    ![邻接矩阵法](images/邻接矩阵法.png)

2. 邻接表法

    ![邻接表法](images/邻接表法.png)

    定义:

    ```c
    ＃define   MaxVerNum  100          /*最大顶点数为100*/
    // 邻接表类型 ：
    typedef  struct  ArcNode
    { 
        int  adjvex;              /*邻接点域*/
        InfoType  *Info;     /*表示边上信息的域info*/
        struct ArcNode * next;    /*指向下一个邻接点的指针域*/
    } ArcNode ;    

    // 表头结点类型 ：
    typedef  struct  Vnode
    {
        VertexType   vertex;          /*顶点域*/
        ArcNode  * firstedge;        /*边表头指针*/
    } Vnode,  AdjList [MaxVertexNum];   

    // 图的类型 ： 
    typedef   struct
    {
        AdjList   vertices;         /*邻接表*/
        int   vexnum,  arcnum;          /*顶点数和边数*/
    } ALGraph;      /*ALGraph是以邻接表方式存储的图类型*/

    ```

### 图的两种搜索方法和图连的连通性；

#### 图的两种搜索方法

![DFS_BFS_sample](images/DFS_BFS_sample.png)

两个基本函数

```c
int FirstAdjVex(ALGraph G, int v)
{  
    // 返回G中第v个顶点的第1个邻接点的序号。如果v无邻接点，返回0。
    if(!G.vertices[v].firstarc) 
        return(0);
    else 
        return(G.vertices[v].firstarc->adjvex);
}

int NextAdjVex(ALGraph G, int v, int w)
{  
    // 返回G中第v个顶点的相对于顶点w的下一个邻接点的序号。
    // 如果v无相对于顶点w的下一个邻接点，返回0。
    ArcNode *p;
    p=G.vetrices[v].firstarc;
    while( p && p->adjvex!=w)
        p=p->nextarc;
    if(p->adjvex==w && p->nextarc)
        return(p->nextarc->adjvex);
    else 
        return(0);
}

```

1. DFS(深度优先)

    ```c

    void DFSTraverse( Graph G ) 
    {
        bool visited[MAX] ;  //用于标识结点是否已被访问过     
        for ( k=1; k<=G.vexnum; ++k ) 
            visited[k] = FALSE;
        for ( k=1; k<=G.vexnum; ++k )
            if ( !visited[ k ] )
                DFS(G, k);
    }

    void DFS( Graph G,  int v )
    {  
        visited[v] = TRUE;  
        VISIT( v );  // 访问图G中第v个顶点
        for (w=FirstAdjVex(G, v); w>0; w=NextAdjVex(G, v, w)) 
            if ( !visited[ w ] )
                DFS(G, w);
    }

    ```

2. BFS(广度优先)

    ```c

    void BFSTraverse( Graph G ) 
    { 
        bool visited[MAX] ;  //用于标识结点是否已被访问过     
        for (v=1; v<=G.vexnum; ++v)  
            visited[v] = FALSE;
        InitQueue(Q);
        for(v=1; v<=G.vexnum; ++v)
            if ( !visited[v] ) 
            {  
                visited[v]=TRUE;
                VISIT(v);
                EnQueue(Q, v);
                while (!EmptyQueue(Q))
                { 
                    DeQueue(Q,u); 
                    for(w=FirstAdjVex(G, u); w>0; w=NextAdjVex(G, u, w))
                        if( !visited[w] )  
                        {  
                            visited[w]=TRUE; 
                            VISIT(w); 
                            EnQueue(Q, w); 
                        }
                } // end while
            } // end if
    }

    ```

### 两种最小生成树的生成方法；

1. Prim 算法

2. Kruskal 算法

### 各种求最短路径的方法；

1. Dijkstra 算法

2. Floyed 算法

### 用顶点表示活动和用边表示活动的两种网络结构特点和相关操作的实现算法。

## （七）排序

### 插入排序法(含折半插入排序法)、选择排序法、泡排序法、快速排序法、堆积排序法、归并排序、基数排序等排序方法排序的原理、规律和特点；

### 各种排序算法的时空复杂度的简单分析。

## （八）索引结构与散列

### 线性索引结构、倒排表、静态搜索树的结构和特点；

### B树的结构；

### 散列的实现原理和各种操作的实现算法。