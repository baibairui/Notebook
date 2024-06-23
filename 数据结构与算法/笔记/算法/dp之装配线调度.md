# dp经典问题：装配线调度

装配线调度问题（Assembly Line Scheduling Problem）是一个经典的动态规划问题。这个问题的目标是通过在两条装配线上调度任务，来最小化完成整个装配过程所需的总时间。

---

## 问题描述

**假设有两条装配线，每条装配线上有𝑛个工作站。每个工作站都需要一定的时间来处理其任务：**

$$
a_1[i]  \gets 第一条装配线处理第 i 个任务所需要的时间
$$
$$
a_2[i]  \gets 第二条装配线处理第 i 个任务所需要的时间
$$


**此外，从一个装配线切换到另一装配线是需要时间的**

$$
t_1[i] \gets 装配线 1 切换到装配线 2 并到达第 i 个工作站的时间。
$$
$$
t_2[i] \gets 装配线 2 切换到装配线 1 并到达第 i 个工作站的时间。
$$

**最初进入装配线的时间**

$$
e_1 \gets 表示进入装配线 1 的时间。
$$

$$
e_2 \gets 表示进入装配线 2 的时间。
$$

**离开装配线的时间**

$$
x_1 \gets 表示离开装配线1的时间
$$

$$
x_2 \gets 表示离开装配线2的时间
$$

## 问题分析

**Step1：识别状态**

$$
T_i[j] \gets 到达第 i 条装配线上第j个工作站的最短时间
$$

**Step2：给出边界条件**

最初进入装配线的时间为
$$
T_1[0] = e_1+a_1[0]
$$
$$
T_2[0] = e_2+a_2[0]
$$

**Step3：写出状态转移方程**

为了从一个工作站转移到下一个工作站，我们有两种选择：继续在当前装配线上，或者切换到另一条装配线。每次都是从最优子问题解的状态转移到当前状态，具体的状态转移方程如下：

$$
T_1[i] = min(T1[i-1]+a_1[i],T2[i-1]+a_1[i]+t_2[i])
$$
$$
T_2[i] = min(T2[i-1]+a_2[i],T1[i-1]+a_2[i]+t_1[i])
$$


**Step3：递推最终状态**

从进入装配线开始进行递推，每一次的状态都是最优子问题解，最终构成了最优结构。

$$
T_n=min(T_1[n-1]+x1,T_2[n-1]+x2)
$$

```cpp
#include<iostream>
#include<vector>

using namespace std;

int assembly(vector<int>&a1,vector<int>&a2,vector<int>&t1,vector<int>&t2,int e1,int e2,int x1,int x2,int n){
    vector<int>T1(n);
    vector<int>T2(n);
    T1[0]=e1+a1[0];
    T2[0]=e2+a2[0];
    for(int i=1;i<n;i++){
        T1[i]=min(T1[i-1]+a1[i],T2[i-1]+a2[i]+t2[i]);
        T2[i]=min(T2[i-1]+a2[i],T1[i-1]+a1[i]+t1[i]);
    }
    return min(T1[n-1]+x1,T2[n-1]+x2);
}

int main() {
    vector<int> a1 = {4, 5, 3, 2};
    vector<int> a2 = {2, 10, 1, 4};
    vector<int> t1 = {0, 7, 4, 5};
    vector<int> t2 = {0, 9, 2, 8};
    int e1 = 10, e2 = 12, x1 = 18, x2 = 7;
    int n = a1.size();
    
    cout << "Minimum cost: " << assembly(a1, a2, t1, t2, e1, e2, x1, x2, n) << endl;

    return 0;
}
```