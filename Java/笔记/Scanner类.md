# Scanner类

java.util.Scanner 是 Java5 的新特征，我们可以通过 Scanner 类来获取用户的输入

**基本语法**
```java
Scanner s = new Scanner(System.in);
```

---

## 读取数据：
Scanner 类提供了多种方法来读取不同类型的数据：
### nextLine()：读取输入的下一行。

在 Java 中，Scanner 类的 nextLine() 方法用于读取输入源中的下一行，直到遇到换行符（通常是按下 Enter 键产生的）。这个方法非常重要，因为它能够读取整行输入，包括空格，这在处理用户输入时非常有用。

当你调用 nextLine() 方法时，**Scanner 会从当前位置开始读取字符，直到它遇到换行符**。换行符也被读取（但不包括在返回的字符串中），这意味着下次读取将从下一行开始。如果当前行没有其他输入，它将返回一个空字符串。

**示例**

```java
import java.util.Scanner;

public class ReadLines {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Please enter your full name:");
        String fullName = scanner.nextLine();
        System.out.println("Your full name is: " + fullName);
        
        System.out.println("Enter your age:");
        if(scanner.hasNextInt()) {
            int age = scanner.nextInt();
            scanner.nextLine(); // 清除缓冲区中的换行符
            System.out.println("You are " + age + " years old.");
        } else {
            System.out.println("Invalid age input. Please enter a valid integer.");
            scanner.nextLine(); // 清除错误输入和随后的换行符
        }
        
        System.out.println("Enter your favorite quote:");
        String quote = scanner.nextLine();
        System.out.println("Your favorite quote is: \"" + quote + "\"");
        
        scanner.close();
    }
}
```

### nextInt()、nextDouble()、nextFloat() 等：读取并返回指定类型的下一个完整标记。

在 Java 中，Scanner 类提供了多种方法来读取不同类型的数据，其中 nextInt(), nextDouble(), 和 nextFloat() 是常用的方法，用于读取整数、双精度浮点数和单精度浮点数。这些方法都是用来解析输入源中的下一个符合对应数据类型的标记（token）。

**nextInt()**
- 用途：用于从输入中读取下一个整数。
- 返回类型：int
- 异常：如果输入的下一个标记不能解析为整数，nextInt() 会抛出 InputMismatchException。
- 行为：此方法不读取行尾的换行符。因此，紧随其后的 nextLine() 调用会读取到空行。

**nextDouble()**
- 用途：用于从输入中读取下一个双精度浮点数。
- 返回类型：double
- 异常：如果输入的下一个标记不能解析为双精度浮点数，nextDouble() 会抛出 InputMismatchException。
- 注意：它受区域设置的影响，如在某些区域设置中，分隔符是逗号而不是点。

**nextFloat()**
- 用途：用于从输入中读取下一个单精度浮点数。
- 返回类型：float
- 异常：如果输入的下一个标记不能解析为单精度浮点数，nextFloat() 会抛出 InputMismatchException。
- 注意：和 nextDouble() 一样，nextFloat() 的行为也受到区域设置的影响。

**示例代码**
这里是一个示例，展示如何使用 nextInt(), nextDouble(), 和 nextFloat()：
```java
import java.util.Scanner;

public class ReadNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            System.out.println("Enter an integer:");
            int intValue = scanner.nextInt();
            System.out.println("You entered the integer: " + intValue);

            System.out.println("Enter a double:");
            double doubleValue = scanner.nextDouble();
            System.out.println("You entered the double: " + doubleValue);

            System.out.println("Enter a float:");
            float floatValue = scanner.nextFloat();
            System.out.println("You entered the float: " + floatValue);

        } catch (InputMismatchException e) {
            System.out.println("Input error: Please ensure you enter the correct type of number.");
        } finally {
            scanner.nextLine(); // Consume the newline character left by numerical inputs
            scanner.close();
        }
    }
}
```
### next()：读取输入的下一个词（以空格为分隔符）。

在 Java 中，Scanner 类的 next() 方法是用来读取输入中的下一个标记（通常是一个单词），这个标记以空格为分隔符。next() 方法对于读取由空格、制表符或其他分隔符分隔的字符串非常有用。

**next() 方法的主要特性：**
- 返回类型：String，返回输入中的下一个标记。
- 行为：此方法只会读取到第一个遇到的空格、制表符或换行符之前的字符串。它不包括任何类型的分隔符。
- 用途：通常用于读取单个单词或连续的非空白字符。

**使用场景**
读取单个单词：如果你只需要从用户输入中获取单个单词或连续的字符序列，不包括任何空格，那么 next() 是一个很好的选择。
连续读取多个单词：可以在循环中使用 next() 来连续读取多个单词，直到达到某个条件或输入结束。

```java
import java.util.Scanner;

public class NextExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Please enter some words separated by spaces:");
        String firstWord = scanner.next();  // 读取第一个单词
        System.out.println("The first word you entered is: " + firstWord);
        
        if (scanner.hasNext()) {  // 检查是否还有更多的单词
            String secondWord = scanner.next();  // 读取第二个单词
            System.out.println("The second word you entered is: " + secondWord);
        }
        
        scanner.close();
    }
}

```