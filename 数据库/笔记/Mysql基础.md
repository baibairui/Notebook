# Mysql基础

MySQL 是关系型数据库管理系统的一种实现，它实现了关系型数据库的基本概念和功能。MySQL 使用表格来表示数据，并通过 SQL 进行数据管理。


---

## 一. Sql语句的分类

### **DDL(Data Defination Language)**

数据定义语言，用来定义数据库对象 **(数据库，表，字段)**

**示例**
```mysql
-- 创建表
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    BirthDate DATE,
    Position VARCHAR(50)
);

-- 修改表
ALTER TABLE Employees ADD Email VARCHAR(100);

-- 删除表
DROP TABLE Employees;

-- 清空表
TRUNCATE TABLE Employees;
```

### **DML(Data Manipulation Language)**

数据操作语言，用来对数据库表中的数据进行**增(INSERT),改(UPDATE),删(DELETE)**

**示例**
```mysql
-- 插入数据
INSERT INTO Employees (EmployeeID, FirstName, LastName, BirthDate, Position)
VALUES (1, 'John', 'Doe', '1980-01-01', 'Manager');

-- 更新数据
UPDATE Employees SET Position = 'Senior Manager' WHERE EmployeeID = 1;

-- 删除数据
DELETE FROM Employees WHERE EmployeeID = 1;
```

### DQL(Data Query Language)

数据查询语言，用来查询数据库中的记录

**示例**
```mysql
SELECT column1, column2 FROM table_name WHERE condition;
```

### DCL(Data Control Language)

数据控制语言，用来创建数据库用户，控制数据库的访问权限

**示例**
```mysql
-- 授予权限
GRANT SELECT, INSERT ON Employees TO user1;

-- 撤销权限
REVOKE INSERT ON Employees FROM user1;
```

## 二. DDL操作详解

