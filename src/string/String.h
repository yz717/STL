#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	const static size_t npos = -1;
	typedef char* iterator;
	typedef const char* const_iterator;
	// 构造函数：根据 C 字符串初始化
	String(const char* str = "");

	// 拷贝构造函数
	String(const String& rhs);

	// 赋值操作符重载
	String& operator=(const String& rhs);

	// 重新分配内存
	void reserve(size_t new_capacity);

	// 追加字符
	void push_back(char ch);

	// 追加字符串
	void append(const char* str);

	// 重载+=运算符
	String& operator+=(char ch);
	String& operator+=(const char* str);

	// 插入函数
	String& insert(size_t pos, char ch);
	String& insert(size_t pos, const char* str);

	// 删除函数
	String& erase(size_t pos, size_t len = npos);

	//调整字符串大小
	void resize(size_t new_size, char ch = '\0');

	// 查找函数
	size_t find(char ch, size_t pos = 0)const;
	size_t find(const char* str, size_t pos = 0)const;

	// 重载[]运算符
	char& operator[](size_t i);
	const char& operator[](size_t i)const;

	// 析构函数
	~String();

	// 返回 C 字符串
	const char* c_str()const;

	// 迭代器
	iterator begin();
	const_iterator begin()const;

	iterator end();
	const_iterator end()const;

	// 大小相关
	size_t Size()const;
	size_t length()const;
	size_t Capacity()const;
private:
	char* data;
	size_t size;
	size_t capacity;
};

istream& operator>>(istream& is, String& str);
istream& getline(istream& is, String& str);
ostream& operator<<(ostream& os, const String& str);


bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
