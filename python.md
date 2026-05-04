# 列表：
1. 计算
    1. len(list)
    2. [1,2,3] + [4,5,6]  ,得到  [1,2,3,4,5,6]
    3. ['hi']*3 ,得到 ['hi','hi','hi']
    4. print(3 in [1,2,3])  得到 True
    5. for x in list:print(x) 进行遍历列表
2. 函数及方法：
    len(list)计算长度
    max(list)得出最大的
    min(list)得出最小的
    list(seq)将元组转换为列表
    list.append(obj)在末尾添加
    list.count(obj)得出某一个元素的出现次数
    list.extend(seq)在末尾加上一个列表
    list.index(obj)得出某一个元素第一次出现的位数
    list.insert(index,obj)在特定的某一位添加
    list.pop(数字)弹出某一位的元素，默认为最后一个
    list.remove(obj)删除某个元素的第一个
    list.reverse()反转列表
    list.sort([func])从小到大排序，字母按字母表顺序

# 元组：
1. tuple 和 List 非常类似，但是 tuple 一旦初始化就不能修改。元组（tuple） 不可变是指当你创建了 tuple 时候，它就不能改变了，也就是说它也没有 append()，insert() 这样的方法，但它也有获取某个索引值的方法，但是不能赋值。是因为 tuple 是不可变的，所以代码更安全。

tuple = (123,'where',456)
元组中只包含一个元素时，需要在元素后面添加逗号 , tuple4=(123,)
如果不加逗号，创建出来的就不是 元组（tuple），而是指 123 这个数了。
这是因为括号 () 既可以表示元组（tuple），又可以表示数学公式中的小括号，这就产生了歧义。
2. 修改：
元组中的元素值是不允许修改的，但我们可以对元组进行连接组合，还有通过修改其他列表的值从而影响 tuple 的值。
list = [12,34]
tuple = (123,'when','what',list)
print(tuple)
list[0] = 23
list[2] = 45
print(tuple)

两次的输出：
(123, 'when', 'what', [12, 34])
(123, 'when', 'what', [23, 45])

可以看到，tuple1 有四个元素，最后一个元素是一个 List ，List 列表里有两个元素。

当我们把 List 列表中的两个元素 12 和 34 修改为 23 和 45 的时候，从输出来的 tuple1 的值来看，好像确实是改变了。

但其实变的不是 tuple 的元素，而是 list 的元素。

tuple 一开始指向的 list 并没有改成别的 list，所以，tuple 所谓的“不变”是说，tuple 的每个元素，指向永远不变。注意是 tupe1 中的第四个元素还是指向原来的 list ，是没有变的，我们修改的只是列表 List 里面的元素。

3. 删除
tuple 元组中的元素值是不允许删除的，但我们可以使用 del 语句来删除整个元组
del tuple

4. 计算：和list一样
    1. len(list)
    2. [1,2,3] + [4,5,6]  ,得到  [1,2,3,4,5,6]
    3. ['hi']*3 ,得到 ['hi','hi','hi']
    4. print(3 in [1,2,3])  得到 True
    5. for x in list:print(x) 进行遍历列表

5. 函数及方法：
len(tuple)	计算元组元素个数
max(tuple)	返回元组中元素最大值
min(tuple)	返回元组中元素最小值
tuple(seq)	将列表转换为元组


# 字典：
1. 字典是另一种可变容器模型，且可存储任意类型对象。

字典的每个键值(key=>value)对用冒号(:)分割，每个对之间用逗号(,)分割，整个字典包括在花括号({})中 ,格式如下所示：

dict = {key1 : value1, key2 : value2 }
print['key']来查找对应的value

2. 函数及方法：
len(dict)	计算字典元素个数
str(dict)	输出字典可打印的字符串表示
type(variable)	返回输入的变量类型，如果变量是字典就返回字典类型
dict.clear()	删除字典内所有元素
dict.copy()	返回一个字典的浅复制
dict.values()	以列表返回字典中的所有值
popitem()	随机返回并删除字典中的一对键和值
dict.items()	以列表返回可遍历的(键, 值) 元组数组

# set:

python 的 set 和其他语言类似, 是一个无序不重复元素集, 基本功能包括关系测试和消除重复元素。
set 和 dict 类似，但是 set 不存储 value 值的。
1. 创建：
创建一个 set，需要提供一个 list 作为输入集合

set1=set([123,456,789])
print(set1)
输出结果：{456, 123, 789}

传入的参数 [123,456,789] 是一个 list，而显示的 {456, 123, 789} 只是告诉你这个 set 内部有 456, 123, 789 这 3 个元素，显示的顺序跟你参数中的 list 里的元素的顺序是不一致的，这也说明了 set 是无序的。

还有一点，我们观察到输出的结果是在大括号中的，经过之前的学习，可以知道，tuple (元组) 使用小括号，list (列表) 使用方括号, dict (字典) 使用的是大括号，dict 也是无序的，只不过 dict 保存的是 key-value 键值对值，而 set 可以理解为只保存 key 值。

重复的自动过滤了：

set1=set([123,456,789,123,123])
print(set1)
输出的结果：{456, 123, 789}

2. 添加
set 添加元素
通过 add(key) 方法可以添加元素到 set 中，可以重复添加，但不会有效果
set1 = set([123,334,456])
print(set1)
set1.add(567)
print(set1)

3. 删除元素
通过 remove(key) 方法可以删除 set 中的元素
set1 = set([123,334,456])
print(set1)
set1.remove(334)
print(set1)

4. set 的运用
因为 set 是一个无序不重复元素集，因此，两个 set 可以做数学意义上的 union(并集), intersection(交集), difference(差集) 等操作。

# 循环
1. range函数
使用 range(x) 函数，就可以生成一个从 0 到 x-1 的整数序列。

如果是 range(a,b) 函数，你可以生成了一个左闭右开的整数序列。

其实例子中的 range(3) 可以写成 range(0,3), 结果是一样的。

其实使用 range() 函数，我们更多是为了把一段代码重复运行 n 次。

比如 range(0,10,2)  , 它的意思是：从 0 数到 10（不取 10 ），每次间隔为 2 。

#  Python 中的 值传递（按值传递） 机制
1. e = 1
def change(e):
    e = 1000
    return e
print(change(e))
print(e)

输出结果：1000
         1


f = [1,2,3]
print(f)
def change_1(f):
    f.append(4)
    return f
print(change_1(f))
print(f)

输出结果：[1, 2, 3]
         [1, 2, 3, 4]
         [1, 2, 3, 4]

可见e前后发生了变化，但f并没有发生变化
因为：
这里主要是函数参数的传递中，传递的是类型对象，之前也介绍了 Python 中基本的数据类型等。
而这些类型对象可以分为**可更改类型**和**不可更改的类型**。

在 Python 中，
字符串，整形，浮点型，tuple 是不可更改的对象，
而 list ， dict 等是可以更改的对象。


# 迭代器
迭代器，迭代器是一个可以记住遍历的位置的对象。

迭代器对象从集合的第一个元素开始访问，直到所有的元素被访问完结束。

迭代器只能往前不会后退。

迭代器有两个基本的方法：iter() 和 next(),且字符串，列表或元组对象都可用于创建迭代器，迭代器对象可以使用常规 for 语句进行遍历，也可以使用 next() 函数来遍历。

1. 字符创创建迭代器对象
str1 = 'liangdianshui'
iter1 = iter ( str1 )

2. list对象创建迭代器
list1 = [1,2,3,4]
iter2 = iter ( list1 )

3. tuple(元祖) 对象创建迭代器
tuple1 = ( 1,2,3,4 )
iter3 = iter ( tuple1 )

for 循环遍历迭代器对象
for x in iter1 :
    print ( x , end = ' ' )


# list 生成式（列表生成式）

1. 创建 list 的方式

list1 = list(range(1,11))
print(list1)
就可以生成1到10的列表

2. list 生成式的创建

- [expr for iter_var in iterable] 

expr：表达式，基于迭代变量进行计算

iter_var：迭代变量

iterable：可迭代对象（列表、元组、字符串、range等）

- [expr for iter_var in iterable if cond_expr]

if cond_expr：条件表达式，只有满足条件的元素才会被处理

第一种语法：首先迭代 iterable 里所有内容，每一次迭代，都把 iterable 里相应内容放到iter_var 中，再在表达式中应用该 iter_var 的内容，最后用表达式的计算值生成一个列表。

第二种语法：加入了判断语句，只有满足条件的内容才把 iterable 里相应内容放到 iter_var 中，再在表达式中应用该 iter_var 的内容，最后用表达式的计算值生成一个列表。

其实不难理解的，因为是 list 生成式，因此肯定是用 [] 括起来的，然后里面的语句是把要生成的元素放在前面，后面加 for 循环语句或者 for 循环语句和判断语句。

例如：
// 传统方式
squares = []
for x in range(1, 6):
    squares.append(x ** 2)
squares = [1, 4, 9, 16, 25]

// 列表推导式
squares = [x ** 2 for x in range(1, 6)]
squares = [1, 4, 9, 16, 25]

list1= [(x+1,y+1) for x in range(3) for y in range(5)] 
print(list1)

# 类的定义和调用
## 定义
-  类是一个变量和函数的集合。把同性质的包装在一个类里，这样就方便我们重复使用。
 用 class 语句来自定义一个类的，其实这就好比我们是用 def 语句来定义一个函数一样。
class ClassA():
    var1 = 100
    var2 = 0.01
    var3 = '两点水'

    def fun1():
        print('我是 fun1')

    def fun2():
        print('我是 fun1')

    def fun3():
        print('我是 fun1')

上面我们就定义了一个类，类名叫做 ClassA , 类里面的变量我们称之为属性，那么就是这个类里面有 3 个属性，分别是 var1 , var2 和 var3 。除此之外，类里面还有 3 个类方法 fun1() , fun2() 和 fun3() 。


## 调用

类里面的变量叫属性  调用：类.变量
类里面的函数叫方法  调用：类.函数()

## 类方法如何调用类属性

class ClassA():
    var1 = 'hello'

    @classmethod
    def fun1(cls){
        print('我是yu' + cls.var1)
    }
print(ClassA.var1)
print(ClassA.fun1())
    
类方法，想要调用类属性，需要以下步骤：

在方法上面，用 @classmethod 声明该方法是类方法。只有声明了是类方法，才能使用类属性
类方法想要使用类属性，在第一个参数中，需要写上 cls , cls 是 class 的缩写，其实意思就是把这个类作为参数，传给自己，这样就可以使用类属性了。
类属性的使用方式就是 cls.变量名
记住喔，无论是 @classmethod 还是 cls ,都是不能省去的。

## 类方法传参
class ClassA():
    var1 = 'hello'

    @classmethod
    def fun1(cls ， age){
        print('我是yu' + cls.var1)
        print('我'+str(age)+'岁了')
    }
print(ClassA.var1)
print(ClassA.fun1(要输入的参数))

## 修改和增加类属性
1. 从内部增加和修改类属性
class ClassC():
    var1 = 'hello'
    @classmethod
    def fun1(cls):
        print('修改前的var1:'+ cls.var1)
        cls.var1 = input('修改后的var1(请输入内容):')
        print('现在要新增一个var2')
        cls.var2 = input('请输入新增的var2:')
        print('新增后的var2为：'+cls.var2)
print(ClassC.fun1())
print(ClassC.var1)
print(ClassC.var2)
2. 从外部增加和修改类属性
class ClassC():
    var1 = 'hello'
    @classmethod
    def fun1(cls):
        print('修改前的var1:'+ cls.var1)

ClassC.var1 = input('修改后的var1:')
print(ClassC.fun1())
print(ClassC.var1)
ClassC.var2 = input('增添的var2:')
print(ClassC.var2)

- 区别就在于是cls.var还是Class.var,还有就是一个写在了类里面，一个写在了类外面

# 类和对象

## 类和对象的关系

这部分内容主要讲类和对象，我们先来说说类和对象之间的关系。

类是对象的模板

我们得先有了类，才能制作出对象。

类就相对于工厂里面的模具，对象就是根据模具制造出来的产品。

从模具变成产品的过程，我们就称为类的实例化。

类实例化之后，就变成对象了。也就是相当于例子中的产品。

类是模板，对象是产品，从类到对象，即从模板到产品，就是类的实例化。

## 类的实例化


对比：
1. 

class ClassA():
    var1 = 'hello'

    @classmethod
    def fun1(cls):
        print('var1 值为:' + cls.var1)

2. 
实例化
class ClassA(object):
    var1 = 'hello'

    def fun1(self):
        print('var值为：'+self.var1)

#实例化
a = ClassA()
#实例化之后，使用它里面的方法
a.fun1()
这个是会调用fun1的，会有输出
#或者是使用它里面的属性
print(a.var1)
print(a.fun1())

>主要的不同点有：

类方法里面没有了 @classmethod 声明了，不用声明他是类方法
类方法里面的参数 cls 改为 self
类的使用，变成了先通过 实例名 = 类() 的方式实例化对象，为类创建一个实例，然后再使用 实例名.函数() 的方式调用对应的方法 ，使用 实例名.变量名 的方法调用类的属性

其中，self并不一定要写成self，写成什么都可以，只是像cls代表类一样，self代表着对象，是编程习惯，这也是我们的编程规范。

这里我们实例化对象的时候，就使用 self 。

而且 self 是所有类方法位于首位、默认的特殊参数。

除此之外，在这里，还要强调一个概念，当你把类实例化之后，里面的属性和方法，就不叫类属性和类方法了，改为叫**实例属性**和**实例方法**，也可以叫**对象属性**和**对象方法**。

为什么要这样强调呢？

因为一个类是可以创造出多个实例对象出来的。


## 实例属性和类属性
一个类可以实例化多个对象出来。

1. 
类属性改变了，实例属性会跟着改变。

这很好理解，因为我们的实例对象就是根据类来复制出来的，类属性改变了，实例对象的属性也会跟着改变。

2. 
那么相反，如果实例属性改变了，类属性会改变吗？

答案当然是不能啦。因为每个实例都是单独的个体，不能影响到类的。

## 实例方法和类方法
1. 我们需要改变类方法，就用到了类的重写。

我们使用了 类.原始函数 = 新函数 就完了类的重写了。

要注意的是，这里的赋值是在替换方法，并不是调用函数。所以是不能加上括号的，也就是 类.原始函数() = 新函数() 这个写法是不对的。
2. 
那么如果实例方法改变了，类方法会改变吗？

如果这个问题我们需要验证的话，是不是要重写实例的方法，然后观察结果，看看类方法有没有改变，这样就能得出结果了。

可是我们是不能重写实例方法。

会直接报错。

# 初始化函数 

## 什么是初始化函数

1. class ClassA(object):
    def __init__(self):
        print('实例化成功')

#实例化
a = ClassA()      [——带上（）时说明在调用]

2. 当代码在执行 a = ClassA() 的语句时，就**自动**调用了 __init__(self) 函数。

而这个 __init__(self) 函数就是初始化函数，也叫构造函数。

初始化函数的写法是固定的格式：中间是 init，意思是初始化，然后前后都要有【两个下划线】，然后 __init__() 的括号中，第一个参数一定要写上 self，不然会报错。

**self 是类方法的第一个参数，代表类的实例本身（也就是创建的对象）。**
self.name 用于将传入的参数 name 存储为实例属性

构造函数（初始化函数）格式如下：

def __init__(self,[...):

3. 初始化函数一样可以传递参数的

class ClassA(object):
    def __init__(self,str):
        print('实例化成功')
        print(str)

#实例化
a = ClassA('what can i say?')

## 析构函数

既然一个类在创建的时候，会调用构造函数，那么理所当然，当一个类销毁的时候，就会调用析构函数。

析构函数语法如下：

def __del__(self,[...):




class ClassA(object):
    def __init__(self,str):
        print('实例化成功')
        print(str)

    def __del__(self):
        print('实例化销毁了')

#实例化
a = ClassA('what can i say?')
del a       ——调用这个方法可以销毁对象
**目前看来似乎只有初始化函数会被自动执行**


# 类的继承

## 定义类的继承

1. 
比如有一个旧类，是可以算平均数的。然后这时候有一个新类，也要用到算平均数，那么这时候我们就可以使用继承的方式。新类继承旧类，这样子新类也就有这个功能了。

通常情况下，我们叫旧类为父类，新类为子类。

首先我们来看下类的继承的基本语法：

class ClassName(BaseClassName):
    <statement-1>
    .
    .
    .
    <statement-N>

- 在定义类的时候，可以在括号里写继承的类(父类)，如果不用继承类的时候，也要写继承 object 类，因为在 Python 中 object 类是一切类的父类。


2. 当然上面的是单继承，Python 也是支持多继承的，具体的语法如下：
lass ClassName(Base1,Base2,Base3):
    <statement-1>
    .
    .
    .
    <statement-N>

- 多继承有一点需要注意的：若是父类中有相同的方法名，而在子类使用时未指定，python 在圆括号中父类的顺序，从左至右搜索 ， 即方法在子类中未找到时，从左到右查找父类中是否包含方法。

- 继承的子类的好处：

    - 会继承父类的属性和方法
    - 可以自己定义，覆盖父类的属性和方法

## 调用父类的方法

一个类继承了父类后，可以直接调用父类的方法的，比如下面的例子，UserInfo2 继承自父类 UserInfo ，可以直接调用父类的 get_account 方法。

class UserInfo(object):
    lv = 5

    def __init__(self, name, age, account):
        self.name = name
        self._age = age
        self.__account = account

    def get_account(self):
        return self.__account


class UserInfo2(UserInfo):
    pass


if __name__ == '__main__':
    userInfo2 = UserInfo2('两点水', 23, 347073565);
    print(userInfo2.get_account())


## 重写父类的方法

class UserInfo(object):
    lv = 5

    def __init__(self, name, age, account):
        self.name = name
        self._age = age
        self.__account = account

    def get_account(self):
        return self.__account

    @classmethod
    def get_name(cls):
        return cls.lv

    @property
    def get_age(self):
        return self._age


class UserInfo2(UserInfo):
    def __init__(self, name, age, account, sex):
        super(UserInfo2, self).__init__(name, age, account)
        self.sex = sex;


if __name__ == '__main__':
    userInfo2 = UserInfo2('两点水', 23, 347073565, '男');
    # 打印所有属性
    print(dir(userInfo2))
    # 打印构造函数中的属性
    print(userInfo2.__dict__)
    print(UserInfo2.get_name())


[__dict__ 是Python对象的特殊属性

作用：以字典形式返回对象的实例属性

与 dir() 的区别：

dir()：返回**所有可访问的属性和方法名**

__dict__：只返回实例自己的属性（不包括方法）]

print(dir(userInfo2))

输出：['Iv', '_UserInfo__account', '__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__firstlineno__', '__format__', '__ge__', '__getattribute__', '__getstate__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__static_attributes__', '__str__', '__subclasshook__', '__weakref__', '_age', 'get_account', 'get_age', 'get_name', 'name', 'sex']

print(userInfo2.__dict__)

输出：{'name': 'rainball', '_age': 18, '_UserInfo__account': 1751182077, 'sex': '男'}


if __name__ == '__main__':

作用：这是Python程序的入口点检查

原理：

当Python文件直接运行时，__name__ 的值是 '__main__'

当Python文件被其他文件导入时，__name__ 的值是模块名（文件名）

目的：确保代码只在直接运行时执行，被导入时不执行

## 子类的类型判断

使用isinstance()函数进行判断

class User1(object):
    pass


class User2(User1):
    pass


class User3(User2):
    pass


if __name__ == '__main__':
    user1 = User1()
    user2 = User2()
    user3 = User3()
    # isinstance()就可以告诉我们，一个对象是否是某种类型
    print(isinstance(user3, User2))
    print(isinstance(user3, User1))
    print(isinstance(user3, User3))
    # 基本类型也可以用isinstance()判断
    print(isinstance('两点水', str))
    print(isinstance(347073565, int))
    print(isinstance(347073565, str))

输出：

True
True
True
True
True
False

# 类的多态

- 多态的概念其实不难理解，它是指对不同类型的变量进行相同的操作，它会根据对象（或类）类型的不同而表现出不同的行为。


# Python 模块简介

在 Python 中，一个 .py 文件就称之为一个模块（Module）。

hahahahaha!!!!!  感觉被骗了。

# 模块的使用

Python 模块的使用跟其他编程语言也是类似的。你要使用某个模块，在使用之前，必须要导入这个模块。导入模块我们使用关键字 import。

import 的语法基本如下：

import module1[, module2[,... moduleN]

而我们想直接导入某个模块中的某一个功能，也就是属性和方法的话，我们可以使用 from···import 语句。

- 导入的其实就是一个python程序文件。