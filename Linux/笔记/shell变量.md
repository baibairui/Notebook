# Shell变量

在 Shell 中，变量是用来存储和检索数据值的标识符。Shell 变量可以存储字符串、整数或者其他数据类型的值,但是最常用的还是**字符串和整数**。

---

## 变量的赋值

```bash
my_variable="Hello, World" //这里给my_variable赋值了一个字符串

my_var=1234 //这里给my_var 赋值了整数
```

在这里，my_variable 是变量的名称，Hello, World 是存储在该变量中的值。请注意，等号两边不能有空格。


## 变量的访问

访问变量时要在**变量名前加上'$'**

```bash
echo $my_variable  # 输出 Hello, World
```

## 变量的拼接

Shell 不需要特别的语法就可以拼接变量，只要将它们写在一起即可：

```bash
greeting="Hello, "
name="Alice"
message=$greeting$name
echo $message  # 输出 Hello, Alice
```

## 数组变量

在 Bash 中，你可以创建数组变量来存储多个值：

```bash
my_arr=(1 2 3 4 5)

my_arr[5]=6 #可以直接通过索引向数组添加元素，不用考虑扩容的问题

my_array+=(7) #如果不指定索引的话，自动追加到尾部

echo ${my_arr[1]} #访问index==1的元素

echo ${my_arr[@]} #访问数组中的所有元素

echo ${my_arr[*]} #访问数组中的所有元素

echo ${#my_arr[@]} #获取数组中的元素个数

unset my_arr[5] #删除数组中的某个元素


echo ${my_array[@]:1:2} #从索引为 1 开始，获取接下来的两个元素

# 遍历数组
for i in "${my_array[@]}"; do
  echo $i
done

# 将数组元素排序
sorted_array=($(for i in "${my_array[@]}"; do echo $i; done | sort))

#创建一个关联数组(哈希表)
declare -A my_map

my_map["br"]="hanhan"
my_map["hanhan"]="br"

#输出关联数组的所有键
echo ${!my_map[@]}

#输出关联数组的所有值
echo ${my_map[@]}
```


## 运算

原生的Bash编程不支持简单的数学运算，但是可以通过其他外部工具来实现，其中最常用的是**expr计算工具**

```bash

a=10
b=20


echo $(expr $a + $b)

echo $(expr $a - $b)

echo $(expr $a \* $b)#这里要用'\'进行转义

echo $(expr $a / $b)

echo $(expr $a == $b)

echo $(expr $a != $b)

```

