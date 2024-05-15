# Shell函数

linux shell 可以用户定义函数，然后在shell脚本中可以随便调用。

---

## 定义格式

```bash

[ function ] funname [()]

{

    action;

    [return int;]

}

```

**说明：**

1、可以带 **function fun() 定义**，也可以直接 fun() 定义,不带任何参数。
2、参数返回:
- **可以显示加：return 返回**
- 如果不加，将以最后一条命令运行结果，作为返回值

**下面的例子定义了一个函数并进行调用：**

```bash

hello(){
    echo "hihihihihi"
}

echo "this is my function"

hello

echo "done"
```
> 输出 ：
this is my function
hihihihihi      //调用了hello()
done


**下面定义一个带有 return 语句的函数：**

```bash
funAdd(){
    echo "please enter two number"
    echo "first"
    read num1
    echo "second"
    read num2

    return $(expr $num1 + $num2)

funAdd()

echo $?
}
```

## 函数参数

在Shell中，调用函数时可以向其传递参数。在函数体内部，通过 $n 的形式来获取参数的值，例如，$1表示第一个参数，$2表示第二个参数...

**带参数的函数示例：**

```bash
funAddwithparm(){
    echo $1
    echo $2
    echo $3
    echo $(expr $1 + $2 + $3)
}

funAddwithparm 1 2 3

echo funAddwithparm 1 3 5
```

