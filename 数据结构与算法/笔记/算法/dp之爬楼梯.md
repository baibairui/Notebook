# dp经典问题：爬楼梯

---

## [爬楼梯](https://leetcode.cn/problems/three-steps-problem-lcci/description/)

*三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。*

**Step1: 识别问题**

这个问题要求我们计算 **小孩上到第n阶台阶有多少种方法**

**Step2：定义状态**

$$
dp[i] <- 小孩上到第n阶台阶的方法数量，定义为 第 i 个状态
$$

**Step3：确定状态转移方程**

这里 **小孩每次可以上1阶，2阶或3阶** ,也就是说小孩可以从前1阶，2阶或者3阶上到当前台阶

**也就是说当前状态由前三个状态决定**

$$
dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
$$

**Step4：确定初始状态和边界**

$$
dp[0]=1\\
dp[1]=1\\
dp[2]=2\\
dp[3]=4
$$


**Step5：计算目标状态值**

只需要从第四个状态开始自下而上的状态推导即可

**代码**
```cpp
class Solution {
public:
    int waysToStep(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        const int mod = 1000000007;

        for (int i = 4; i <= n; ++i) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};
```


