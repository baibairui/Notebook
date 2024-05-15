# Algorithm

算法是解决特定问题的一系列定义明确的指令序列。算法通常具有以下特征：

- **有限性**：算法必须保证在有限的步骤之后结束。
- **确定性**：算法的每个步骤必须精确无误，没有任何歧义。
- **输入**：算法具有零个或多个输入，这些输入来自于特定的集合。
- **输出**：算法至少有一个输出，是与输入相关的处理结果。
- **有效性**：算法的所有操作都必须足够基础，以便能够准确并在有限的时间内完成。

## 算法分析关注的方面

分析算法时，我们会考虑：

- **正确性**：算法是否正确无误地解决了问题。
- **效率**：算法在解决问题时所需的资源量，通常关注时间复杂度和空间复杂度。
- **健壮性**：算法对错误输入或意外情况的处理能力。
- **可用性**：算法的适用范围和普遍性。


## 算法复杂度
### O(n)

如果存在正整数c和N，对于所有的n>=N,有f(n)<=cg(x),则f(n)=O(g(n))。<br>

f(x) = O(g(x)) 表示的含义是f(x)以g(x)为上界<br>
O(n)计算的是最差的复杂度<br>
![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/72ae45c2-4af6-4559-94dd-b9280f52b8ee)<br>


### Ω(n)

如果存在正整数c和N，对于所有的n>=N,有f(n)>=cg(x),则f(n)=Ω(g(n))。<br>

f(x) = Ω(g(x)) 表示的含义是f(x)以g(x)为下界<br>
Ω(n)计算的是最优的复杂度<br>
![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/de554cca-5ce7-4e88-bdde-62faf440d68a)

### Θ(n)

如果存在正整数c1，c2和N，对于所有的n>=N,有c2g(x)>=f(n)>=c1g(x),则f(n)=Θ(g(n))<br>
若 f(x) = Ω(g(x)) 并且 f(x) = O(g(x)) ， 则 f(x)=Θ(g(n))<br>
![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/d40e9b23-b82d-49e7-a9a3-20fcc970caa6)

## 排序算法

### 冒泡排序
- **基本思想**：重复遍历待排序序列，比较相邻两个元素，如果它们的顺序错误就把它们交换过来。过程重复直到不需要再交换，即序列完全有序。
- **时间复杂度**：平均和最坏情况下都是 O(n^2)，最好情况是 O(n)。
- **空间复杂度**：O(1)。
- **稳定性**：稳定。
- **代码实现**
```` cpp
void sort::bubbleSort(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}
````
### 选择排序
- **基本思想**：首先在未排序序列中找到最小（大）元素，放到排序序列的起始位置，然后再从剩余未排序元素中继续寻找最小（大）元素，放到已排序序列的末尾。以此类推，直到所有元素排序完毕。
- **时间复杂度**：平均和最坏情况下都是 O(n^2)。
- **空间复杂度**：O(1)。
- **稳定性**：不稳定。
- **代码实现**
```` cpp
void sort::selectionSort(vector<int>&arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i; // 初始化当前最小值的索引为i
        for (int j = i + 1; j < n; j++) {
            // 查找最小值的索引
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // 交换当前位置i和最小值位置minIdx的元素
        std::swap(arr[i], arr[minIdx]);
    }
}
````
### 插入排序
- **基本思想**：通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
- **时间复杂度**：平均和最坏情况下是 O(n^2)，最好情况是 O(n)。
- **空间复杂度**：O(1)。
- **稳定性**：稳定。
- **代码实现**
```` java

````
### 快速排序
- **基本思想**：选择一个“基准”元素，分区过程将数组分为两个部分，使得一部分的元素都比基准小，另一部分的元素都比基准大，然后递归地对这两部分继续进行快速排序。
- **时间复杂度**：平均情况下是 O(n log n)，最坏情况下是 O(n^2)。
- **空间复杂度**：平均是 O(log n)。
- **稳定性**：不稳定。
- **代码实现**
```` java

````
### 归并排序
- **基本思想**：将已有序的子序列合并，得到完全有序的序列；即先分解序列为子序列，使每个子序列有序，然后再合并子序列。
- **时间复杂度**：平均和最坏情况下都是 O(n log n)。
- **空间复杂度**：O(n)，需要额外的空间来合并序列。
- **稳定性**：稳定。
- **代码实现**
```` java

````
### 基数排序
- **基本思想**：按照低位先排序，然后收集；再按照高位排序，然后再收集；以此类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
- **时间复杂度**：O(nk)，其中 n 是排序元素个数，k 是数字位数。
- **空间复杂度**：O(n+k)，需要额外的空间来存放临时排序的结果。
- **稳定性**：稳定。
- **代码实现**
```` java

````
### 相关习题

## 查找算法
- **顺序查找**

代码实现
```` java

````
- **二分查找**

代码实现
```` java

````
### 相关习题

## 搜索算法
- **广度优先搜索**
- **深度优先搜索**
### 相关习题
**深度优先搜索**

**广度优先搜索**

## 前缀和及其变体

### 前缀和

#### 概念
前缀和是一种用于快速求解区间和问题的技术。给定一个数组 `arr`，前缀和的每个元素 `sum[i]` 代表从 `arr[0]` 到 `arr[i]` 的总和，可以表示为：

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/668907be-966d-4e49-9bf1-dc84561d3f9c)<br>
![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/5a5f4082-d742-4a37-8dbd-aed413731ebd)<br>

这种方法可以快速计算任意区间的总和，通过下列公式：

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/f120f3ab-d92e-4242-9ce6-58d872a71210)


#### 用法
前缀和适用于多次查询数组某个固定区间的场景，能将区间和查询的时间复杂度降到 `O(1)`。

#### 实现
```java
public int[] buildPrefixSum(int[] arr) {
    int[] sum = new int[arr.length + 1];
    sum[0] = 0;
    for (int i = 1; i <= arr.length; i++) {
        sum[i] = sum[i - 1] + arr[i - 1];
    }
    return sum;
}

public int queryPrefixSum(int[] sum, int l, int r) {
    return sum[r + 1] - sum[l];
}
````

### 前缀积

#### 概念
前缀积是前缀和的一个变体，用于快速计算数组的乘积区间。对于数组 arr，前缀积 prod[i] 代表从 arr[0] 到 arr[i] 所有元素的乘积，可以表示为：

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/e9621e2e-722d-4cc2-ac64-2a24a3a9bcb1)<br>
![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/26befc8e-758a-4857-9ea5-04d11faf6cf7)<br>

进而得到：

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/21c5e107-51d4-462e-a036-e7327cda3821)


#### 用法
与前缀和类似，前缀积可以快速计算数组区间乘积。

#### 实现
````java
public int[] buildPrefixProduct(int[] arr) {
    int[] prod = new int[arr.length + 1];
    prod[0] = 1;
    for (int i = 1; i <= arr.length; i++) {
        prod[i] = prod[i - 1] * arr[i - 1];
    }
    return prod;
}
````

### 异或前缀和

#### 概念
异或前缀和是用于快速计算数组异或区间的技术。对于数组 arr，异或前缀和 xsum[i] 代表从 arr[0] 到 arr[i] 所有元素的异或结果，可以表示为：

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/e0ce2fd3-d75b-4d73-8710-f9a9b134585f)<br>

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/703fe0b3-7a21-4b41-a6f3-c040326af808)<br>

进而得到：

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/0da8197f-07b1-4dfa-8323-a44434a69e52)<br>


#### 用法
利用异或运算的性质，可以快速求出任意区间内元素的异或总和

#### 实现
````java
public int[] buildXorPrefixSum(int[] arr) {
    int[] xsum = new int[arr.length + 1];
    xsum[0] = 0;
    for (int i = 1; i <= arr.length; i++) {
        xsum[i] = xsum[i - 1] ^ arr[i - 1];
    }
    return xsum;
}
````
### 二维前缀和
二维前缀和是一种用于处理二维数组（或矩阵）区域和查询的高效方法。<br>
与一维前缀和类似，它通过预计算一个辅助数组来加速区域和的查询，使得无论查询区域的大小如何，计算区域和的时间复杂度都能保持为常数级别（O(1)）。<br>

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/5e8a4a63-4597-4ed5-8b93-bf723c2872d0)<br>

![image](https://github.com/baibairui/Data-Structure-and-Algorthim/assets/123094711/0571cbfe-9340-489b-a318-e7a21bfcc99c)<br>


#### 实现
```` java
class NumMatrix {
    int[][]presum;

    public NumMatrix(int[][] matrix) {
    if(matrix.length == 0 || matrix[0].length == 0) return;
    int m = matrix.length;
    int n = matrix[0].length;
    presum = new int[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int top = (i > 0) ? presum[i-1][j] : 0;
            int left = (j > 0) ? presum[i][j-1] : 0;
            int topLeft = (i > 0 && j > 0) ? presum[i-1][j-1] : 0;
            presum[i][j] = matrix[i][j] + top + left - topLeft;
        }
    }
}
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
    int total = presum[row2][col2];
    int top = (row1 > 0) ? presum[row1-1][col2] : 0;
    int left = (col1 > 0) ? presum[row2][col1-1] : 0;
    int topLeft = (row1 > 0 && col1 > 0) ? presum[row1-1][col1-1] : 0;
    return total - top - left + topLeft;
}
}

````


### 相关力扣题链接

**线性前缀和** <br>

[一维数组的动态和](https://leetcode.cn/problems/running-sum-of-1d-array/description/)<br>

[寻找数组的中心下标](https://leetcode.cn/problems/find-pivot-index/description/)<br>

[和可被K整除的子数组](https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/)<br>

[找出中枢整数](https://leetcode.cn/problems/find-the-pivot-integer/description/)<br>

[寻找最高海拔](https://leetcode.cn/problems/find-the-highest-altitude/description/)<br>

[逐步求和得到正数的最小值](https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/description/)

[一维区域和检索](https://leetcode.cn/problems/range-sum-query-immutable/description/)<br>

**异或前缀和** <br>

[子数组异或查询](https://leetcode.cn/problems/xor-queries-of-a-subarray/description/)<br>

**二维前缀和** <br>

[二维区域和检索](https://leetcode.cn/problems/range-sum-query-2d-immutable/description/)<br>

[矩阵区域和](https://leetcode.cn/problems/matrix-block-sum/description/)<br>

[找出第K大的异或值](https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/description/)<br>
## 位运算

## 贪心算法

## 动态规划
### 线性DP
### 0/1背包
### 完全背包
### 多重背包

## 图论

## 字符串算法
