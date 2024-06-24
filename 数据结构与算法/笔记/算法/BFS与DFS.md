# BFS与DFS

**BFS和DFS** 是最简单实现的搜索算法，其他的搜索算法其实都是在他们的基础上发展优化而来的。

---

**[力扣模板题](https://leetcode.cn/problems/route-between-nodes-lcci/description/)**

这里要优化一下才可以过这道题

## 1. BFS

**BFS** 通过 **队列来实现** 每次都会先遍历当前节点的邻接节点

```cpp
//这里是用邻接表来表示图
bool bfs(vector<vector<int>>graph,int start,int target){
   std::queue<int>toVis;
   toVis.push(start);//先把起点加入
   while(!toVis.empty()){
        int node=toVis.front();
        toVis.pop();
        if(node==target)return true;
        //这里是可以优化的，不用每次都遍历整个图
        for(int neigh:graph){
            if(neigh[0]==node){
                toVis.push(neigh[1]);
            }
        }
   }
    return false;
}
```

## 2. DFS

**DFS** 通过 **栈来实现** 每次都会先遍历一条路线上的邻接节点

```cpp
//这里是用邻接表来表示图
bool bfs(vector<vector<int>>graph,int start,int target){
   std::stack<int>toVis;
   toVis.push(start);//先把起点加入
   while(!toVis.empty()){
        int node=toVis.top();
        toVis.pop();
        if(node==target)return true;
        //这里是可以优化的，不用每次都遍历整个图
        for(int neigh:graph){
            if(neigh[0]==node){
                toVis.push(neigh[1]);
            }
        }
   }
    return false;
}
```


