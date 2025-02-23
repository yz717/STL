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
	// ���캯�������� C �ַ�����ʼ��
	String(const char* str = "");

	// �������캯��
	String(const String& rhs);

	// ��ֵ����������
	String& operator=(const String& rhs);

	// ���·����ڴ�
	void reserve(size_t new_capacity);

	// ׷���ַ�
	void push_back(char ch);

	// ׷���ַ���
	void append(const char* str);

	// ����+=�����
	String& operator+=(char ch);
	String& operator+=(const char* str);

	// ���뺯��
	String& insert(size_t pos, char ch);
	String& insert(size_t pos, const char* str);

	// ɾ������
	String& erase(size_t pos, size_t len = npos);

	//�����ַ�����С
	void resize(size_t new_size, char ch = '\0');

	// ���Һ���
	size_t find(char ch, size_t pos = 0)const;
	size_t find(const char* str, size_t pos = 0)const;

	// ����[]�����
	char& operator[](size_t i);
	const char& operator[](size_t i)const;

	// ��������
	~String();

	// ���� C �ַ���
	const char* c_str()const;

	// ������
	iterator begin();
	const_iterator begin()const;

	iterator end();
	const_iterator end()const;

	// ��С���
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
