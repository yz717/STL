#include "String.h"


// 构造函数：根据 C 字符串初始化
String::String(const char* str)
{
	size = strlen(str);
	capacity = size;
	data = new char[capacity + 1];
	strcpy(data, str);
}

// 拷贝构造函数
String::String(const String& rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	data = new char[capacity + 1];
	strcpy(data, rhs.data);
}

// 赋值操作符重载
String& String::operator=(const String& rhs)
{
	// 检查自赋值
	if (this != &rhs)
	{
		delete[] data; // 释放原有的内存资源
		size = rhs.size;
		capacity = rhs.capacity;
		data = new char[capacity + 1];
		strcpy(data, rhs.data);
	}
	return *this;
}

// 重新分配内存
void String::reserve(size_t new_capacity)
{
	// 如果新的容量小于当前容量，不做任何事情
	if (new_capacity > capacity) {
		char* new_data = new char[new_capacity + 1];
		strcpy(new_data, data);
		delete[] data;// 释放原有的内存资源
		data = new_data;
		capacity = new_capacity;
	}
}

// 追加字符
void String::push_back(char ch)
{
	if (size == capacity)
	{
		// 重新分配内存
		// 先判断capacity是否为0，如果为0，新的容量为2，否则为原来的2倍
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		reserve(new_capacity);
	}
	data[size++] = ch;
	data[size] = '\0'; // 添加字符串结束符
}

// 追加字符串
void String::append(const char* str)
{
	size_t new_size = size + strlen(str);
	if (new_size > capacity)
	{
		// 重新分配内存
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		// 扩容到足够容纳新字符串的大小,以2倍数扩容
		while (new_capacity < new_size)
		{
			new_capacity *= 2;
		}
		reserve(new_capacity);
	}
	strcat(data, str);
	size = new_size;
}

// 重载+=运算符
String& String::operator+=(char ch)
{
	push_back(ch);
	return *this;
}
String& String::operator+=(const char* str)
{
	append(str);
	return *this;
}

// 插入函数
String& String::insert(size_t pos, char ch)
{
	assert(pos <= size);
	if (size == capacity)
	{
		// 重新分配内存
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		reserve(new_capacity);
	}

	// 将pos位置及其后面的字符向后移动一个位置
	for (size_t i = size + 1; i > pos; --i)
	{
		data[i] = data[i - 1];
	}

	data[pos] = ch;
	++size;
	return *this;
}

String& String::insert(size_t pos, const char* str)
{
	assert(pos <= size);
	size_t len = strlen(str);
	size_t new_size = size + len;
	if (new_size > capacity)
	{
		// 重新分配内存
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		// 扩容到足够容纳新字符串的大小,以2倍数扩容
		while (new_capacity < new_size)
		{
			new_capacity *= 2;
		}
		reserve(new_capacity);
	}

	// 将pos位置及其后面的字符向后移动len个位置
	for (size_t i = size + len; i > pos + len - 1; --i)
	{
		data[i] = data[i - len];
	}

	// 将str插入到pos位置
	for (size_t i = 0; i < len; ++i)
	{
		data[pos + i] = str[i];
	}
	size = new_size;
	return *this;
}

// 删除函数
String& String::erase(size_t pos, size_t len)
{
	assert(pos < size);
	// 如果len超过pos到字符串末尾的长度，只删除pos到字符串末尾的长度
	if (len > size - pos) {
		data[pos] = '\0';
		size = pos;
	}
	else {
		// 将pos+len位置及其后面的字符向前移动len个位置
		size_t i = pos + len;
		while (i <= size)
		{
			data[pos++] = data[i++];
		}
		size -= len;
	}
	return *this;
}

// 调整字符串大小
void String::resize(size_t new_size, char ch)
{
	if (new_size > size)
	{
		if (new_size > capacity)
		{
			// 重新分配内存
			reserve(new_size);
		}

		// 将ch添加到字符串末尾
		for (size_t i = size; i < new_size; ++i)
		{
			data[i] = ch;
		}
	}
	data[new_size] = '\0'; // 添加字符串结束符
	size = new_size;
}


// 查找函数
size_t String::find(char ch, size_t pos) const
{
	for (size_t i = pos; i < size; ++i) {
		if (data[i] == ch) {
			return i;
		}
	}
	return npos;
}
size_t String::find(const char* str, size_t pos) const
{
	char* p = strstr(data + pos, str);
	return p ? p - data : npos;
}

// 析构函数
String::~String()
{
	delete[] data;
}

// 返回 C 字符串
const char* String::c_str()const 
{
	return data;
}

// 迭代器
String::iterator String::begin()
{
	return data;
}
String::const_iterator String::begin() const
{
	return data;
}
String::iterator String::end()
{
	return data + size;
}
String::const_iterator String::end() const
{
	return data + size;
}

// 大小相关
size_t String::Size() const
{
	return size;
}
size_t String::length() const
{
	return size;
}
size_t String::Capacity() const
{
	return capacity;
}

// 重载输入输出
istream& operator>>(istream& is, String& str)
{
	char ch;
	ch = is.get();
	while (ch != ' ' && ch != '\n') {
		str.push_back(ch);
		ch = is.get();// 读取下一个字符,可以读取空格
	}
	return is;
}
istream& getline(istream& is, String& str)
{
	char ch;
	ch = is.get();
	while (ch != '\n') {
		str.push_back(ch);
		ch = is.get();// 读取下一个字符,可以读取空格
	}
	return is;
}
ostream& operator<<(ostream& os, const String& str)
{
	os << str.c_str();
	return os;
}

// 重载比较运算符
bool operator==(const String& lhs, const String& rhs)
{
	int ret = strcmp(lhs.c_str(), rhs.c_str());
	return ret == 0;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs)
{
	int ret = strcmp(lhs.c_str(), rhs.c_str());
	return ret < 0;
}

bool operator>(const String& lhs, const String& rhs)
{
	int ret = strcmp(lhs.c_str(), rhs.c_str());
	return ret > 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const String& lhs, const String& rhs)
{
	return !(lhs < rhs);
}

// 重载[]运算符
char& String::operator[](size_t i)
{
	return data[i];
}

const char& String::operator[](size_t i) const
{
	return data[i];
}
