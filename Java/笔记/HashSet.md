# HashSet

HashSet 是 Java 集合框架中的一个重要实现类，用于存储不重复的元素。**它基于 HashMap 实现**，具有高效的插入、删除和查找操作。实际上，HashSet 的每个元素都作为 HashMap 的键存储，而 HashMap 的值是一个固定的常量对象。

---

## HashSet 的特点

- **不允许重复元素**：每个元素在集合中只能出现一次。
- **无序**：元素的存储顺序不是按照插入顺序，而是根据哈希值来决定的。
- **允许存储一个 null 值。**
- **线程不安全：** 如果在多线程环境下使用，需要手动同步。

## 1.HashSet的常用方法

```java
import java.util.HashSet;
import java.util.Iterator;

public class HashSetExample {
    public static void main(String[] args) {
        HashSet<String> set = new HashSet<>();

        // 添加元素 add()
        set.add("Apple");
        set.add("Banana");
        set.add("Orange");

        // 检查是否包含元素 contains()
        System.out.println("Contains Apple: " + set.contains("Apple"));
        System.out.println("Contains Grape: " + set.contains("Grape"));

        // 删除元素 remove()
        set.remove("Banana");

        // 遍历集合 
        System.out.println("Elements in set:");
        for (String item : set) {
            System.out.println(item);
        }

        // 使用迭代器遍历集合
        Iterator<String> iterator = set.iterator();
        while (iterator.hasNext()) {
            String item = iterator.next();
            System.out.println("Iterator: " + item);
        }

        // 清空集合 clear()
        set.clear();
        System.out.println("Set is empty: " + set.isEmpty());
    }
}
```

## 2.HashSet 底层实现

**HashSet** 是使用**HashMap** 来存储元素的，存储的每一个元素都是作为**Key** 存储到**HashMap**容器中的。

而每个**key**对应的**value**都是相同的一个对象，因此**HashSet**中是不存在重复元素的。

**源码**
```java
public class HashSet<E> extends AbstractSet<E> implements Set<E>, Cloneable, java.io.Serializable {
    private transient HashMap<E, Object> map;

    //相同的常量对象，用final修饰保证不会被改变
    private static final Object PRESENT = new Object();

    public HashSet() {
        map = new HashMap<>();
    }

    public boolean add(E e) {
        return map.put(e, PRESENT) == null;
    }

    public boolean contains(Object o) {
        return map.containsKey(o);
    }

    public boolean remove(Object o) {
        return map.remove(o) == PRESENT;
    }

    // Other methods...
}
```

## 3.HashSet的工作原理

### 3.1 插入

调用 add 方法时，HashSet 实际上是将元素作为键插入到 HashMap 中，值是一个固定的常量对象 PRESENT。如果键已存在，返回 false；否则，返回 true。

\[element \to hashCode() \to hash() -> index\]
\[arr[index] \gets <key,value>\]
\[key \gets element\]
\[value \gets PRESENT\]
**源码**
```java
public boolean add(E e) {
    return map.put(e, PRESENT) == null;
}
```
### 3.2 删除

调用 remove 方法时，HashSet 实际上是调用 HashMap 的 remove 方法，删除指定的键。

```java
public boolean remove(Object o) {
    return map.remove(o) == PRESENT;
}
```
### 3.3 查询

调用 contains 方法时，HashSet 实际上是调用 HashMap 的 containsKey 方法，检查是否包含指定的键。

\[x \gets target\]
\[x \to hashCode() \to hash() \to index \]
\[res.equals(arr[index].getValue())\]
```java
public boolean contains(Object o) {
    return map.containsKey(o);
}
```





