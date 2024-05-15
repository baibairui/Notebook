# Comparable和Comparator的区别

在Java中，Comparable 和 Comparator 接口都用于定义对象的排序逻辑，但它们在使用方式和应用场景上有显著的区别。

---

## Comparable接口

- **内部比较器：**

**Comparable是一个排序接口**，类通过实现这个接口的**compareTo(Object o)** 方法来定义自身对象的自然排序。如果一个类实现了Comparable接口，它就可以直接通过**Collections.sort()** 或**Arrays.sort()** 方法进行排序，不需要额外指定比较器。

- **用途：**

主要用于定义对象的“默认”或“自然”排序顺序。
- **返回值：**

compareTo() 方法返回一个整数，具有以下含义：
负整数：当前对象小于指定的对象。
零：当前对象等于指定的对象。
正整数：当前对象大于指定的对象。

**例如，一个Person类可能根据年龄或姓名进行自然排序**

```java
public class Person implements Comparable<Person> {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public int compareTo(Person other) {
        if(other.age<this.age){
            return 1;
        }else if(other.age>this.age){
            return -1;
        }else{
            return 0;
        }
    }
}
```


## Comparator 接口

- **外部比较器：**

Comparator是一个功能性接口，它定义了一个**compare(T o1, T o2)** 方法，用于比较两个同类型的对象。它通常作为**一个匿名类或lambda表达式** 传递给排序方法（如Collections.sort(list, comparator)），用于定义一个自定义的排序规则。

- **用途：**

当你不能修改原始类，或者当你需要除了自然排序以外的其他排序方式时，Comparator非常有用。它也支持多个不同的排序标准，或者在运行时根据不同的需求选择不同的排序策略。

```java
import java.util.*;

public class ComparatorExample {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();
        people.add(new Person("Alice", 32));
        people.add(new Person("Bob", 24));
        people.add(new Person("Charlie", 26));

/*
        Comparator<Person> byName = new Comparator<Person>() {
            @Override
            public int compare(Person p1, Person p2) {
                return p1.getName().compareTo(p2.getName());
            }
        };
*/
        Collections.sort(people, new Comparator<Person>(){
            @Override
            public int compare(Person p1,Person p2){
                return p1.getName().compareTo(p2.getName());
            }
        }); // Sort by name using a comparator
    }
}
```

## 对比

**Comparable接口（内部比较器）**
它是一个对象自己必须实现的接口，表示这个对象能够和同类型的另一个对象进行比较。
这个接口定义了一个compareTo()方法，任何实现了Comparable接口的类都必须实现这个方法。
这个方法用来**定义对象的自然排序顺序**，比如，一个数字小的整数应该排在数字大的整数之前。
使用compareTo()方法可以**直接通过Collections.sort()或数组的Arrays.sort()方法** 对对象列表或数组进行排序，不需要指定额外的比较器。

**举个例子：**

```java
public class Person implements Comparable<Person> {
    private int age;

    @Override
    public int compareTo(Person another) {
        return this.age - another.age;//定义自己的排序规则
    }
}
```

**Comparator接口（外部比较器）**

Comparator是一个可以创建一个**独立于对象本身的比较规则。**
当你不能修改原始类或当你需要多种排序方式时，你可以使用Comparator。
Comparator定义了一个compare()方法，它接受两个同类型的对象作为参数。
使用Comparator可以在运行时根据需求指定排序的顺序。

**举个例子：**

```java
public class AgeComparator implements Comparator<Person> {
    @Override
    public int compare(Person p1, Person p2) {
        return p1.getAge() - p2.getAge();
    }
}

public class NameComparator implements Comparator<Person> {
    @Override
    public int compare(Person p1, Person p2) {
        return p1.getName().compareTo(p2.getName());
    }
}
```
在上面的例子中，Person类不需要修改，我们**可以使用AgeComparator来按年龄排序**，或者**使用NameComparator来按名字排序**。

**关键区别**

- **Comparable是“我能和别人比”（对象自己决定如何和别人比）**，实现时需要修改类的内部代码。

- **Comparator是“我能决定别人怎么比”（定义外部的新规则来比较两个对象）**，不需要改变原始类的代码。

