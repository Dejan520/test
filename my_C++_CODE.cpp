#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>   //标准算法头文件
#include<string>

//原生指针也是迭代器
void test01()
{

	int arr[5] = { 1,2,3,4,5 };
	int *p = arr;//指向第一个元素1
	for (int i = 0; i < 5; i++)
	{
		cout << *p << endl;
		p++;
	}
}

void my_print(int val)//回调函数
{
	cout << val << endl;
}

//使用STL的迭代器
void test02()
{
	vector<int>v;//创建一个vector容器，容器中存放的数据类型是int型

	//插入元素
	v.push_back(54); v.push_back(4); v.push_back(5); v.push_back(12); v.push_back(7);

	//遍历元素
	vector<int>::iterator  itbegin = v.begin();//v.begin() 起始迭代器，指向容器的第一个数据
	vector<int>::iterator  itend = v.end(); //结束迭代器，指向的是容器中最后一个元素的下一个位置

	//第一种遍历
	while (itbegin != itend)
	{
		cout << *itbegin << endl;//itbegin当成指针来用
		itbegin++;
	}

	//第二种遍历	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种遍历
	for_each(v.begin(), v.end(), my_print);
}

//自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->my_name = name;
		this->my_age = age;
	}
	int my_age;
	string my_name;
};
void test03()
{
	vector<Person> v;
	Person p1("a", 10); Person p2("rea", 310); Person p3("wr", 788);
	v.push_back(p1); v.push_back(p2); v.push_back(p3);

	//每个容器都有自己专属的迭代器
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//  *it==Person
		cout << (*it).my_name << "	" << (*it).my_age << endl;
	}
}

//存放自定义数据类型指针
void test04()
{
	vector<Person*> v;
	Person p1("a", 10); Person p2("rea", 310); Person p3("wr", 788);
	v.push_back(&p1); v.push_back(&p2); v.push_back(&p3);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		//  *it==Person*
		cout << (*it)->my_name << "	" << (*it)->my_age << endl;
	}

}

//容器嵌套容器
void test05()
{
	vector<int>v1;	vector<int>v2;	vector<int>v3;//三个小容器
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 10);
		v2.push_back(i + 20);
		v3.push_back(i + 100);
	}
	vector<vector<int>>v;//一个大容器
	v.push_back(v1);//小放入大
	v.push_back(v2); v.push_back(v3);
	//遍历大容器
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//(*it)==vector<int>  需要做两层输出
		for (vector<int>::iterator itx = (*it).begin(); itx != (*it).end(); itx++)
		{
			//(*itx)==int
			cout << (*itx) << "	";
		}
		
		cout << endl;//输出完一行小容器,进行换行
	}
}
int main()
{
	test05();
	system("pause");
	return EXIT_SUCCESS;
}
