# Cloneable

在Java中，**Cloneable 接口是一个标记接口**，它用来指示一个类的对象是“可克隆的”，即它们可以通过调用**Object类中的clone()方法** 来创建对象副本。如果一个类实现了Cloneable接口，这表明该类有意图允许对象克隆。

---

## **关键点**

- **标记接口**

Cloneable 没有定义任何方法，它是一个标记接口，用于告诉Object.clone()方法，对于这个类的实例，可以进行字段到字段的复制。

- **默认的浅复制**

Object类的默认clone()方法执行的是浅复制（shallow copy）。这意味着只复制对象本身和对象内的基本数据类型字段，但是不复制对象引用字段所指向的对象。

- **深复制**

如果你需要对象内的所有引用字段也被克隆，你需要覆盖clone()方法并实现深复制（deep copy）。

- **覆盖clone()方法** 

当一个类实现了Cloneable接口，你通常还需要覆盖Object类的clone()方法，并将其访问级别改为public。

- **CloneNotSupportedException**

如果一个对象的类没有实现Cloneable接口，当调用其clone()方法时，将抛出CloneNotSupportedException。

**示例**

```java
public class Example implements Cloneable {
    private int number;
    
    public Example(int number) {
        this.number = number;
    }
    
    // 提供一个公有的 clone 方法，调用超类的 clone 方法
    public Object clone() throws CloneNotSupportedException {
        return super.clone();//这里调用的是浅克隆，只复制了引用的地址
    }
    
    public static void main(String[] args) {
        Example original = new Example(42);
        try {
            Example cloned = (Example) original.clone();
            System.out.println(cloned.number); // 输出将会是 42
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }
}
```

## 什么是深克隆与浅克隆

**深克隆（Deep Clone）** 指的是在克隆对象时，不仅克隆对象本身，还包括对象内部所有层次的属性，即对于所有的引用类型属性，也递归地进行克隆操作。这样，克隆出的新对象与原始对象在内存中是完全独立的，修改新对象的引用类型属性不会影响原始对象的状态。

**浅克隆（Shallow Clone）** 是对象克隆的一种形式，在这种克隆过程中，对象的复制只会复制对象本身和对象中的基本数据类型字段的值。但是，对于对象中的任何引用类型字段，浅克隆并不会创建被引用对象的新实例，而是仅仅复制对这些对象的引用本身。这意味着，如果原始对象和克隆对象中的一个引用类型字段指向了同一个对象，那么对这个对象的修改会影响到两个对象。

在Java中，**Object类提供的clone()方法默认就是执行浅克隆**。如果一个类要启用克隆功能，它需要实现标记接口Cloneable，并重写clone()方法（通常是调用super.clone()）。

**浅克隆的例子**

首先，让我们从浅克隆开始。这里我们将使用Object类的clone()方法进行浅克隆，这种方式只复制对象的非引用字段以及引用的地址，而不复制引用对象本身
，并**没有创建新的对象引用**
```java
class Address {
    public String city;

    public Address(String city) {
        this.city = city;
    }
}

class Person implements Cloneable {
    public Address address;
    public int age;

    public Person(Address address, int age) {
        this.address = address;
        this.age = age;
    }

    @Override
    public Person clone() throws CloneNotSupportedException {
        return (Person) super.clone();  // 浅克隆
    }
}

public class ShallowCloneExample {
    public static void main(String[] args) {
        Address address = new Address("New York");
        Person original = new Person(address, 25);

        Person cloned = null;
        try {
            cloned = original.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

        // 修改原始对象的Address
        original.address.city = "San Francisco";

        System.out.println("Cloned person's city: " + cloned.address.city); // 将输出"San Francisco"
    }
}
```
在这个例子中，修改原始Person对象的address.city字段后，克隆的Person对象中的address.city也被改变了，因为它们共享同一个Address对象的引用。


**深克隆的例子**

**深克隆（Deep Clone）** 是一种在克隆过程中不仅复制对象的基本数据类型的字段，而且对其引用数据类型的字段也创建全新副本的方法。这种克隆方法确保了克隆对象在内存中与原始对象完全独立，对克隆对象的修改不会影响到原始对象，特别是对于引用类型的字段。

```java
class Address implements Cloneable {
    public String city;

    public Address(String city) {
        this.city = city;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}

class Person implements Cloneable {
    public Address address;
    public int age;

    public Person(Address address, int age) {
        this.address = address;
        this.age = age;
    }

    @Override
    public Person clone() throws CloneNotSupportedException {
        Person cloned = (Person) super.clone();
        cloned.address = (Address) this.address.clone();  // 深克隆
        return cloned;
    }
}

public class DeepCloneExample {
    public static void main(String[] args) {
        Address address = new Address("New York");
        Person original = new Person(address, 25);

        Person cloned = null;
        try {
            cloned = original.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

        // 修改原始对象的Address
        original.address.city = "San Francisco";

        System.out.println("Cloned person's city: " + cloned.address.city); // 将输出"New York"
    }
}
```

在深克隆的示例中，即使我们改变了原始Person对象的address.city字段，克隆的Person对象的address.city仍然是"New York"。这是因为在深克隆过程中，**创建了新的对象实例**，因此克隆的Person对象有自己独立的Address实例。

## 深克隆与浅克隆的区别

**浅克隆（Shallow Clone）**

只复制对象到第一层属性，对于属性类型是引用类型的字段，复制的是引用，因此克隆出的对象与原对象共享引用类型的字段。

**深克隆（deep Clone）**

复制对象及其所有的引用类型的属性，直到基本类型数据或不可变对象（如String）为止。深克隆需要递归地复制所有引用类型的成员，直到这个图的叶节点。

## 实现深克隆

**实现深克隆通常有以下几种方法：**

- **递归地克隆所有引用类型属性**

如果一个对象含有引用类型的属性，你需要在clone()方法中不仅仅复制这个引用，而是调用引用类型属性的clone()方法来创建一个完全独立的复制品。

- **使用序列化**

如果对象实现了Serializable接口，你可以通过序列化对象到一个流中，然后再反序列化回来，这样可以自动地进行深克隆。这种方式不需要针对每个对象写克隆的逻辑，但是要求所有的属性类型都是可序列化的，并且性能相对较低。