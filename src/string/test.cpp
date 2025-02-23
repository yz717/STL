#include "String.h"

// 测试构造函数
void test1() {
	String s1;
	String s2("hello");

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}

// 测试拷贝构造函数
void test2() {
	String s1("hello");
	String s2(s1);

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}

// 测试赋值操作符重载
void test3() {
	String s1("hello");
	String s2;
	s2 = s1;

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
}

// 测试+=运算符重载
void test4() {
	String s1("hello");
	s1 += ' ';
	s1 += "world";

	cout << s1.c_str() << endl;
}

// 测试插入函数
void test5() {
	String s1("hello");
	s1.insert(5, " world");
	s1.insert(0, "say ");

	cout << s1.c_str() << endl;
}

// 测试删除函数
void test6() {
	String s1("hello world");
	s1.erase(5, 6);
		cout << s1.c_str() << endl;
}

// 测试调整字符串大小
void test7() {
	String s1("hello");
	s1.resize(10, '!');
	cout << s1.c_str() << endl;
	s1.resize(2);
	cout << s1.c_str() << endl;
}

// 测试查找函数
void test8() {
	String s1("hello world");
	cout << s1.find('o') << endl;
	cout << s1.find("world") << endl;
}

// 测试输入输出
void test9() {
	String s1;
	cin >> s1;
	cout << s1 << endl;
	String s2;
	getline(cin, s2);
	cout << s2 << endl;
}

// 测试比较运算符
void test10() {
	String s1("hello");
	String s2("hello");
	String s3("world");
	cout << (s1 == s2) << endl;
	cout << (s1 == s3) << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 != s3) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 < s3) << endl;
	cout << (s1 > s2) << endl;
	cout << (s1 > s3) << endl;
	cout << (s1 <= s2) << endl;
	cout << (s1 <= s3) << endl;
	cout << (s1 >= s2) << endl;
	cout << (s1 >= s3) << endl;
}


// 测试[]运算符
void test11() {
	String s("hello");
	cout << s[0] << endl;
	cout << s[1] << endl;
	cout << s[2] << endl;
	cout << s[3] << endl;
	cout << s[4] << endl;
}

// 测试迭代器
void test12() {
	String s("hello");
	String::iterator it = s.begin();
	while (it != s.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// 测试Size、Length、Capacity函数
void test13() {
	String s("hello");
	s += " world";
	cout << s.Size() << endl;
	cout << s.length() << endl;
	cout << s.Capacity() << endl;

}
int main() {
	return 0;
}