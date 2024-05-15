# Comparator

在Java中，**Comparator 接口是用于定义两个对象比较规则的接口**。它在 java.util 包中定义，是一个泛型接口，允许你定义自定义的比较逻辑，以此来排序或其他需要比较功能的数据结构处理。Comparator 接口通常用在那些自然顺序不适用或我们不想使用自然顺序的场景中。

---

## Comparator 接口定义

Comparator 是一个泛型接口，可以这样定义：

```java

@FunctionalInterface
public interface Comparator<T> {
    int compare(T o1, T o2);
    boolean equals(Object obj);
}
```

## 核心方法

**int compare(T o1, T o2)**

这个方法用于比较两个类型为 T 的对象。返回值有三种情况：
- **返回负整数**：如果第一个对象应该排在第二个对象之前；
- **返回零**：如果两个对象相等；
- **返回正整数**：如果第一个对象应该排在第二个对象之后。
这个方法的实现必须确保具有 传递性 并且在所有情况下都保持一致。

**boolean equals(Object obj)**

这个方法用于检查当前比较器是否与另一个比较器相等。通常情况下，没有必要重写这个方法。

因为所有的类都是继承于**Object类**，通常都是通过重写**Object类** 中的**hashCode()和equals()**。


## 使用 Comparator 的场景

**定制排序**

通过 Comparator 可以实现任何类型的定制排序，而不仅仅依赖于自然顺序。例如，你可以定义一个Comparator来按照字符串的长度而不是字典顺序来排序字符串。

**Collections.sort() 和 Arrays.sort()**

这些排序方法都有重载版本，接受一个 Comparator 对象作为参数，使得排序行为可以根据传入的 Comparator 来定制,并且通常是通过**匿名内部类的方法来传入**。

**示例:**

```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<String> words = Arrays.asList("Apple", "Banana", "Cherry", "Date");
        
        // 使用匿名内部类创建 Comparator
        Comparator<String> lengthComparator = new Comparator<String>() {
            public int compare(String s1, String s2) {
                return Integer.compare(s1.length(), s2.length());
            }
        };

        Collections.sort(words, lengthComparator);
        
        System.out.println(words);  // 输出可能是 ["Date", "Apple", "Banana", "Cherry"]，基于字符串长度排序
    }
}
```

**优先队列**

PriorityQueue 类在Java中实现了基于优先级的队列机制，优先级的判断就是通过传入的 Comparator 来定义的。

