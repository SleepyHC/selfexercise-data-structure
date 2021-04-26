## 图

分为有向图/无向图

也可以分为带不带权的图



[TOC]



### 储存方式

#### 邻接矩阵：

​	不带权---0/1

​	带权-----0/1/∞  **∞表示为INF**

​	o(n^2)---适用于稠密图

​	无向图的邻接矩阵一定是对称矩阵 

#### 邻接表

​	头节点和边节点

​	例如是以1为头节点，1指向的2，3，4，5，6依次为后续的边节点

还有一些特殊的链表储存结构比如十字链表和邻接多重表





### 遍历

深度优先和广度优先

#### 深度优先遍历

深度优先是从*v*开始，首先方位v，之后访问与v相邻的w，再访问与w相邻的u

--这样可以理解为一种递归，就是访问w时可以被看作是一种以w为首的深度优先遍历，而且每一次为首都是从该头节点开始



#### 广度优先遍历

广度优先是从v开始，首先访问v，之后访问与v相邻的所有节点，再以这些节点分别为首继续广度优先遍历，但是要考虑到一个问题，就是再次为首广度优先遍历时上一层已经遍历完了，所以需要去用队列储存上一层遍历的节点。





#### 最小生成图

https://www.bilibili.com/video/BV1Eb41177d1

prim算法和Kruskal算法