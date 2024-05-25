# HashTable

Hashtable 是一种键值对存储的数据结构，基于哈希表实现。它提供了高效的查找、插入和删除操作。在 Java 中，Hashtable 类是 java.util 包的一部分。

---

## 1.基本使用方法

**代码示例**
```java
Hashtable<String,Integer>table= new Hashtable<>();

//添加元素
table.put("a",1);
table.put("b",2);
table.put("c",3);
//删除元素
table.remove("a");
//获取元素
table.get("b")//返回2
//检查是否存在键或者值
boolean hasApple = table.containsKey("apple"); // 返回 true
boolean hasValue20 = table.containsValue(20); // 返回 false
//遍历
// 使用 Iterator 遍历键
        Iterator<String> keyIterator = table.keySet().iterator();
        while (keyIterator.hasNext()) {
            String key = keyIterator.next();
            System.out.println("Key: " + key);
        }

        // 使用 Iterator 遍历值
        Iterator<Integer> valueIterator = table.values().iterator();
        while (valueIterator.hasNext()) {
            Integer value = valueIterator.next();
            System.out.println("Value: " + value);
        }

        // 使用 Iterator 遍历键值对
        Iterator<Map.Entry<String, Integer>> entryIterator = table.entrySet().iterator();
        while (entryIterator.hasNext()) {
            Map.Entry<String, Integer> entry = entryIterator.next();
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }

        System.out.println("\nUsing Enhanced for loop:");
        // 使用增强型 for 循环遍历键
        for (String key : table.keySet()) {
            System.out.println("Key: " + key);
        }

        // 使用增强型 for 循环遍历值
        for (Integer value : table.values()) {
            System.out.println("Value: " + value);
        }

        // 使用增强型 for 循环遍历键值对
        for (Map.Entry<String, Integer> entry : table.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }

        System.out.println("\nUsing Enumeration:");
```

## 2.底层实现原理

**Hashtable**的底层实现思想也是哈希表并使用链地址法来解决哈希冲突的问题。
**Hashtable**的方法都加上了synchronized关键字，这意味着**Hashtable**是线程安全的集合。但是在高并发的情况下由于只有拿到锁的线程才能操作，因此会导致效率较低

```java
public class Hashtable<K, V> extends Dictionary<K, V> implements Map<K, V>, Cloneable, java.io.Serializable {
    // 初始容量和负载因子
    private static final int INITIAL_CAPACITY = 11;
    private static final float LOAD_FACTOR = 0.75f;

    // 哈希表数组
    private transient Entry<?, ?>[] table;

    // 哈希表中的键值对数量
    private transient int count;

    // 重新哈希的阈值，当键值对数量超过该值时，哈希表会重新调整大小
    private int threshold;

    // 哈希表的负载因子
    private final float loadFactor;

    // Entry 类表示哈希表中的键值对
    private static class Entry<K, V> implements Map.Entry<K, V> {
        final int hash;
        final K key;
        V value;
        Entry<K, V> next;

        protected Entry(int hash, K key, V value, Entry<K, V> next) {
            this.hash = hash;
            this.key = key;
            this.value = value;
            this.next = next;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            if (value == null)
                throw new NullPointerException();
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }

        public boolean equals(Object o) {
            if (!(o instanceof Map.Entry))
                return false;
            Map.Entry<?, ?> e = (Map.Entry<?, ?>) o;

            return (key == null ? e.getKey() == null : key.equals(e.getKey())) &&
                   (value == null ? e.getValue() == null : value.equals(e.getValue()));
        }

        public int hashCode() {
            return hash ^ (value == null ? 0 : value.hashCode());
        }

        public String toString() {
            return key.toString() + "=" + value.toString();
        }
    }

    // 构造函数
    public Hashtable(int initialCapacity, float loadFactor) {
        if (initialCapacity < 0)
            throw new IllegalArgumentException("Illegal Capacity: " + initialCapacity);
        if (loadFactor <= 0 || Float.isNaN(loadFactor))
            throw new IllegalArgumentException("Illegal Load: " + loadFactor);

        this.loadFactor = loadFactor;
        this.table = new Entry<?, ?>[initialCapacity];
        this.threshold = (int) Math.min(initialCapacity * loadFactor, MAX_ARRAY_SIZE + 1);
    }

    public Hashtable(int initialCapacity) {
        this(initialCapacity, LOAD_FACTOR);
    }

    public Hashtable() {
        this(INITIAL_CAPACITY, LOAD_FACTOR);
    }

    public synchronized int size() {
        return count;
    }

    public synchronized boolean isEmpty() {
        return count == 0;
    }

    public synchronized boolean containsKey(Object key) {
        if (key == null) {
            throw new NullPointerException();
        }
        Entry<?, ?> tab[] = table;
        int hash = key.hashCode();
        int index = (hash & 0x7FFFFFFF) % tab.length;
        for (Entry<?, ?> e = tab[index]; e != null; e = e.next) {
            if ((e.hash == hash) && e.key.equals(key)) {
                return true;
            }
        }
        return false;
    }

    public synchronized boolean contains(Object value) {
        if (value == null) {
            throw new NullPointerException();
        }
        Entry<?, ?> tab[] = table;
        for (int i = tab.length; i-- > 0;) {
            for (Entry<?, ?> e = tab[i]; e != null; e = e.next) {
                if (e.value.equals(value)) {
                    return true;
                }
            }
        }
        return false;
    }

    public synchronized V get(Object key) {
        Entry<?, ?> tab[] = table;
        int hash = key.hashCode();
        int index = (hash & 0x7FFFFFFF) % tab.length;
        for (Entry<?, ?> e = tab[index]; e != null; e = e.next) {
            if ((e.hash == hash) && e.key.equals(key)) {
                return (V) e.value;
            }
        }
        return null;
    }

    public synchronized V put(K key, V value) {
        if (key == null || value == null) {
            throw new NullPointerException();
        }

        Entry<?, ?> tab[] = table;
        int hash = key.hashCode();
        int index = (hash & 0x7FFFFFFF) % tab.length;
        for (Entry<K, V> e = (Entry<K, V>) tab[index]; e != null; e = e.next) {
            if ((e.hash == hash) && e.key.equals(key)) {
                V old = e.value;
                e.value = value;
                return old;
            }
        }

        addEntry(hash, key, value, index);
        return null;
    }

    private void addEntry(int hash, K key, V value, int index) {
        Entry<?, ?> tab[] = table;
        if (count >= threshold) {
            rehash();
            tab = table;
            hash = key.hashCode();
            index = (hash & 0x7FFFFFFF) % tab.length;
        }

        Entry<K, V> e = (Entry<K, V>) tab[index];
        tab[index] = new Entry<>(hash, key, value, e);
        count++;
    }

    protected void rehash() {
        int oldCapacity = table.length;
        Entry<?, ?>[] oldMap = table;

        int newCapacity = (oldCapacity << 1) + 1;
        if (newCapacity - MAX_ARRAY_SIZE > 0) {
            if (oldCapacity == MAX_ARRAY_SIZE) {
                return;
            }
            newCapacity = MAX_ARRAY_SIZE;
        }

        Entry<?, ?>[] newMap = new Entry<?, ?>[newCapacity];

        threshold = (int) Math.min(newCapacity * loadFactor, MAX_ARRAY_SIZE + 1);
        table = newMap;

        for (int i = oldCapacity; i-- > 0;) {
            for (Entry<K, V> old = (Entry<K, V>) oldMap[i]; old != null;) {
                Entry<K, V> e = old;
                old = old.next;

                int index = (e.hash & 0x7FFFFFFF) % newCapacity;
                e.next = (Entry<K, V>) newMap[index];
                newMap[index] = e;
            }
        }
    }

    public synchronized V remove(Object key) {
        Entry<?, ?> tab[] = table;
        int hash = key.hashCode();
        int index = (hash & 0x7FFFFFFF) % tab.length;
        for (Entry<K, V> e = (Entry<K, V>) tab[index], prev = null; e != null; prev = e, e = e.next) {
            if ((e.hash == hash) && e.key.equals(key)) {
                if (prev != null) {
                    prev.next = e.next;
                } else {
                    tab[index] = e.next;
                }
                count--;
                V oldValue = e.value;
                e.value = null;
                return oldValue;
            }
        }
        return null;
    }

    public synchronized void clear() {
        Entry<?, ?> tab[] = table;
        for (int index = tab.length; --index >= 0;)
            tab[index] = null;
        count = 0;
    }

    // 其他方法省略...
}

```

### 2.1 底层数据结构

**Hashtable**的哈希数组是基于动态扩容的数组，数组的每个位置都存储着键值对

```java
public class Hashtable<K, V> extends Dictionary<K, V> implements Map<K, V>, Cloneable, java.io.Serializable {
    // 初始容量和负载因子
    private static final int INITIAL_CAPACITY = 11;
    private static final float LOAD_FACTOR = 0.75f;

    // 哈希表数组
    private transient Entry<?, ?>[] table;

    // 哈希表中的键值对数量
    private transient int count;

    // 重新哈希的阈值，当键值对数量超过该值时，哈希表会重新调整大小
    private int threshold;

    // 哈希表的负载因子
    private final float loadFactor;

    // Entry 类表示哈希表中的键值对
    private static class Entry<K, V> implements Map.Entry<K, V> {
        final int hash;
        final K key;
        V value;
        Entry<K, V> next;

        protected Entry(int hash, K key, V value, Entry<K, V> next) {
            this.hash = hash;
            this.key = key;
            this.value = value;
            this.next = next;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            if (value == null)
                throw new NullPointerException();
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }

        public boolean equals(Object o) {
            if (!(o instanceof Map.Entry))
                return false;
            Map.Entry<?, ?> e = (Map.Entry<?, ?>) o;

            return (key == null ? e.getKey() == null : key.equals(e.getKey())) &&
                   (value == null ? e.getValue() == null : value.equals(e.getValue()));
        }

        public int hashCode() {
            return hash ^ (value == null ? 0 : value.hashCode());
        }

        public String toString() {
            return key.toString() + "=" + value.toString();
        }
    }
```

**Hashtable** 的**初始的负载因子是0.75 初始容量是11**，每次达到阈值的时候会进行动态扩容



**与HashMap不同的是HashMap每次都是二倍扩容，Hashtable每次都是扩容为(2n+1)**



### 2.2 哈希映射 

哈希函数的主要作用是将键的哈希码转换为数组中的索引位置。在 Hashtable 中，哈希函数通过调用键的 hashCode() 方法计算哈希码，然后使用如下公式将哈希码转换为数组索引：

```java
int index = (hash & 0x7FFFFFFF) % table.length;
```
- **hash & 0x7FFFFFFF**：这是为了确保哈希码是一个正整数。
- **% table.length**：通过对数组长度取模操作，将哈希码映射到数组的索引范围内。

### 2.3 哈希冲突的解决

**Hashtable 是使用链表来解决哈希冲突的**

JDK1.8 以后的 HashMap 在解决哈希冲突时有了较大的变化，当链表长度大于阈值（默认为 8）时，将链表转化为红黑树（将链表转换成红黑树前会判断，如果当前数组的长度小于 64，那么会选择先进行数组扩容，而不是转换为红黑树），以减少搜索时间

```java
public synchronized V put(K key, V value) {
    if (key == null || value == null) {
        throw new NullPointerException();
    }

    Entry<?, ?> tab[] = table;
    int hash = key.hashCode();
    int index = (hash & 0x7FFFFFFF) % tab.length;
    for (Entry<K, V> e = (Entry<K, V>) tab[index]; e != null; e = e.next) {
        if ((e.hash == hash) && e.key.equals(key)) {
            V old = e.value;
            e.value = value;
            return old;
        }
    }

    addEntry(hash, key, value, index);
    return null;
}

private void addEntry(int hash, K key, V value, int index) {
    Entry<?, ?> tab[] = table;
    if (count >= threshold) {
        rehash();
        tab = table;
        hash = key.hashCode();
        index = (hash & 0x7FFFFFFF) % tab.length;
    }

    Entry<K, V> e = (Entry<K, V>) tab[index];
    tab[index] = new Entry<>(hash, key, value, e);
    count++;
}
```

这里我们可以看到**Hashtable**是不允许储存null值的
```java
if (key == null || value == null) {
        throw new NullPointerException();
    }
```

### 2.4 存储的节点

**Entry 类**

Entry 类是哈希表中存储键值对的基本单元。每个 Entry 对象包含一个键、一个值、哈希码以及指向下一个 Entry 对象的引用（用于处理哈希冲突）。

```java
private static class Entry<K, V> implements Map.Entry<K, V> {
    final int hash;
    final K key;
    V value;
    Entry<K, V> next;

    protected Entry(int hash, K key, V value, Entry<K, V> next) {
        this.hash = hash;
        this.key = key;
        this.value = value;
        this.next = next;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }

    public V setValue(V value) {
        if (value == null)
            throw new NullPointerException();
        V oldValue = this.value;
        this.value = value;
        return oldValue;
    }

    public boolean equals(Object o) {
        if (!(o instanceof Map.Entry))
            return false;
        Map.Entry<?, ?> e = (Map.Entry<?, ?>) o;
        return (key == null ? e.getKey() == null : key.equals(e.getKey())) &&
               (value == null ? e.getValue() == null : value.equals(e.getValue()));
    }

    public int hashCode() {
        return hash ^ (value == null ? 0 : value.hashCode());
    }

    public String toString() {
        return key.toString() + "=" + value.toString();
    }
}
```