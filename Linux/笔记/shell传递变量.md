# Shell传递变量

在 Bash 编程中，参数传递通常指的是向脚本或函数传递数据。这允许脚本根据输入的参数执行不同的操作，使脚本更加灵活和可重用

---

## 1. 脚本参数

当你运行一个 Bash 脚本时，可以在脚本名后面加上空格，并列出要传递的参数：
```bash
./my_script.sh arg1 arg2 arg3 #传递三个参数

# 保存第一个参数到变量
first_arg=$1

# 打印所有参数
echo "All arguments: $@"

# 打印参数个数
echo "Number of arguments: $#"

# 遍历所有参数并打印
for arg in "$@"; do
    echo "Argument: $arg"
done

```

在上述命令中，**arg1、arg2、arg3** 是传递给 my_script.sh 脚本的参数。

在脚本内部，你可以通过位置参数来访问传入的参数：

- $0 - 脚本的名称。

- $1 - 第一个参数。

- $2 - 第二个参数。

- $3 - 第三个参数。

以此类推...

**一些特殊的参数访问**

- $# -访问参数个数
- $@ -访问所有参数

## 2. 函数的参数传递

在 Bash 函数中，参数的传递和处理与脚本相似。你可以定义函数，并在调用函数时传递参数：

```bash
my_function() {
    echo "First parameter: $1"
    echo "Second parameter: $2"
    echo "All parameters: $@"
    echo "Total number of parameters: $#"
}

my_function "param1" "param2" "param3"
```
在函数内部，你使用相同的位置参数 $1, $2, $@, $# 等来访问传递给函数的参数。

