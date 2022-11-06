# c++语法 --- 函数模板和类模板

## 模板

* 核心：模板是面对泛型编程。不依赖于具体类型的通用框架

* 类型：函数模板和类模板

* 优点：

    * 提高代码的复用性





## 函数模板

* 定义：建立一个通用函数，其 返回值类型 和 形参类型 可以不具体定义,用一个虚拟的类型来代表
* 参数类型：模板类型参数和非模板类型参数,区别在于是否有模板类型关键字typename/class

#### 模板类型参数

```c++
template<typename T>
int compareWithTemplateParam(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

int main()
{
    // 显示指定类型，能够发生类型隐式转化
    double d1 = 1.3, d2 = 1.4;
    cout << "double compare result is " << compareWithTemplateParam<double>(d1, d2) << endl;
    char c1 = 'e';
    int c2 = 10;
    cout << "mix type compare result is " << compareWithTemplateParam<char>(c1, c2) << endl;

    // 自动推断类型，不能够不发生类型隐式转化
    int v1 = 5;
    char v2 = 'a';
    // cout << "mix type compare result is " << compareWithTemplateParam(v1, v2) << endl;
}
```

* 函数模板实例化
    * 函数模板只是一段公共的代码逻辑，不能直接编译。在调用函数模板时，会根据实参类型，实例化出特定版本的函数，称为模板实例，对模版实例进行编译链接。
    * 函数模板在编译时实例化。因为c++是分离编译，最后链接。必须将函数模板放在头文件中，编译器在编译期才能看到函数的完整实现，才能实例化。
    * 业务代码举例

#### 非模板类型参数

```c++
#include <iostream>
#include <string.h>
using namespace std;

template<unsigned N, unsigned M>
int compareWithoutTemplateParam(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2); // strcmp:p1>p2返回正数，p1<p2返回负数，=返回0
}

int main()
{
    cout << compareWithoutTemplateParam("mom", "hi") << endl;
}
```

* 定义：非模版类型参数前使用特定类型名，且一定是常量，或者指向静态生命周期对象的指针或引用。
* 代码举例：DUMBS_FillL3SusrModifyMsgBase

#### 模板函数调用原则

1. 先找参数完全匹配的普通函数（非由模板实例化而得的函数）；
2. 再找参数完全匹配的模板函数；
3. 再找实参数经过自动类型转换后能够匹配的普通函数；
    * 可以通过 模板参数列表<> 来强制调用函数模板

```c++
void myPrint(int a, int b)
{
	cout << "调用的是普通函数！" << endl;
}

template<class T>
void myPrint(T a, T b)
{
	cout << "调用函数模板！" << endl;
}  

int main()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);//1、优先调用普通函数

	myPrint<>(a, b);//2、通过空模板参数列表 强制调用函数模板

	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);//3、如果函数模板可以产生更好的匹配 优先调用 函数模板
}
```



## 类模板

* 定义：为了多快好省地定义出一批**相似的类**,可以定义「类模板」，然后**由类模板生成不同的类**
* 类模板与函数模板的区别：
    * 类模板在模板参数列表中可以有默认参数
    * 类模板没有自动类型推导,如果模板参数列表全为默认参数，实例化时可以提供<>

```c++
template<typename T>
class Comp {
public:
    const T& GetConstData() const;
    void IncreaseCnt();
    void DecreaseCnt();
    int GetCnt() const;
private:
    T data;
    static int cnt;
};

template<typename T>
int Comp<T>::cnt = 0;

template<typename T>
const T& Comp<T>::GetConstData() const
{
    return data;
}

template<typename T>
void Comp<T>::IncreaseCnt()
{
    cnt++;
}

template<typename T>
void Comp<T>::DecreaseCnt()
{
    cnt--;
}


template<typename T>
int Comp<T>::GetCnt() const
{
    return cnt;
}

int main()
{
    Comp<int> tddIntraComp{};
    Comp<int> fddIntraComp{};
    cout << "tddIntraComp cnt is " << tddIntraComp.GetCnt() << endl;
    fddIntraComp.IncreaseCnt();
    cout << "tddIntraComp cnt is " << tddIntraComp.GetCnt() << endl;

    Comp<char> tddInterComp{};
    Comp<char> fddInterComp{};
    cout << "tddInterComp cnt is " << tddInterComp.GetCnt() << endl;
    fddInterComp.IncreaseCnt();
    tddInterComp.IncreaseCnt();
    cout << "tddInterComp cnt is " << tddInterComp.GetCnt() << endl;
    cout << "tddIntraComp cnt is " << tddIntraComp.GetCnt() << endl;
    return 0;
}
```



* 类模板的成员的实例化：
    * 模板类成员在调用时才实例化

```c++
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show!" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show!" << endl;
	}
};

template<class T>
class MyClass 
{
public:
	T obj;
  
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

int main()
{
  MyClass<Person1> m1;
  m1.func1();
//  m2.func2(); 
}
```

* 代码举例：class L2MsgFiller





* 类模板与继承：当父类是类模板时
    * Con1:子类声明时，要给父类提供模板实参
    * Con2:子类也是类模板，并把模板参数作为父类的模板实参

```c++
template<class T>
class Base
{
public:
    Base()
    {
        cout << "Base 的数据类型：" << typeid(T).name() << endl;
    }
    T m;
};

class Son : public Base<int>
{};

template<class T1, class T2>
class Son2 :public Base<T1>
{
public:
    Son2()
    {
        cout << "T1 的数据类型：" << typeid(T1).name() << endl;
        cout << "T2 的数据类型：" << typeid(T2).name() << endl;
    }
};

int main()
{
    Son s1;
    Son2<double, char> s2;
}
```



#### 类模板和友元

1. 类模版和非模版友元：友元可以访问类的所有模版实例

2. 非模版类和模版友元：类可以开放访问权限给部分友元模版实例，或全部友元模版实例

3. 类模版和模版友元：
    * 类模版开放相同类型的模版实例给友元的模版实例
    * 类模版可以开放所有实例给部分与自身类型不同的友元模版实例
    * 类模版可以开放所有的模版实例给给所有的友元模版实例

```c++
// 非模版类和模版友元
template<typename T> class Pal1;
class Normal {
    friend class Pal1<Normal>;
    template<typename T> friend class Pal2;
};

// 模版类和模版友元
template<typename T1> class PartPal1;
template<typename Foo> class PartPal2;
template<typename T1> class C;
template<typename T1> bool operator==(const C<T1>&, const C<T1>&);

template<typename T1> class Foo
{
    friend class PartPal1<T1>; // 开放与友元相同类型的模版实例给PartPal1；
    friend class PartPal2<Foo>; // 开放所有模版实例 给部分与自身模版类型不同 的友元模版实例；
    template<typename T2> friend class AllPal; // 开放所有模版实例 给所有友元模版实例，不需要在类前声明该友元
    friend bool operator==<T1>(const C<T1>&, const C<T1>&); // 友元函数
};
```



## 模板的全特化与偏特化

* 定义：就是为已有的模板参数进行一些使其特殊化的指定，使得以前不受任何约束的模板参数，或受到特定的修饰，或完全被指定了下来。
* 分类
    * 全特化：特化所有模板列表里的参数，不需要在编译期确定。适用于**一个模板能应对各种情形，又需要它对于某个特定的类型有着特别的处理**
    * 偏特化：特化部分模板列表里的参数

#### 类模板

```c++
template<typename T1, typename T2>
class Test
{
public:
	Test(T1 i,T2 j):a(i),b(j){cout<<"模板类"<<endl;}
private:
	T1 a;
	T2 b;
};
 
template<>
class Test<int , char>
{
public:
	Test(int i, char j):a(i),b(j){cout<<"全特化"<<endl;}
private:
	int a;
	char b;
};
 
template <typename T2>
class Test<char, T2>
{
public:
	Test(char i, T2 j):a(i),b(j){cout<<"偏特化"<<endl;}
private:
	char a;
	T2 b;
};

int main()
{
    Test<double, double> t1(0.1,0.2); // 类模板
    Test<int , char> t2(1,'A'); // 全特化
    Test<char, bool> t3('A',true); // 偏特化
}
```



#### 函数模板

```c++
//模板函数
template<typename T1, typename T2>
void fun(T1 a , T2 b)
{
	cout<<"模板函数"<<endl;
}
 
//全特化
template<>
void fun<int ,char >(int a, char b)
{
	cout<<"全特化"<<endl;
}
 
//函数不存在偏特化：下面的代码是错误的
/*
template<typename T2>
void fun<char,T2>(char a, T2 b)
{
	cout<<"偏特化"<<endl;
}
*/
```