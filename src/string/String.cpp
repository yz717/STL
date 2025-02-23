#include "String.h"


// ���캯�������� C �ַ�����ʼ��
String::String(const char* str)
{
	size = strlen(str);
	capacity = size;
	data = new char[capacity + 1];
	strcpy(data, str);
}

// �������캯��
String::String(const String& rhs)
{
	size = rhs.size;
	capacity = rhs.capacity;
	data = new char[capacity + 1];
	strcpy(data, rhs.data);
}

// ��ֵ����������
String& String::operator=(const String& rhs)
{
	// ����Ը�ֵ
	if (this != &rhs)
	{
		delete[] data; // �ͷ�ԭ�е��ڴ���Դ
		size = rhs.size;
		capacity = rhs.capacity;
		data = new char[capacity + 1];
		strcpy(data, rhs.data);
	}
	return *this;
}

// ���·����ڴ�
void String::reserve(size_t new_capacity)
{
	// ����µ�����С�ڵ�ǰ�����������κ�����
	if (new_capacity > capacity) {
		char* new_data = new char[new_capacity + 1];
		strcpy(new_data, data);
		delete[] data;// �ͷ�ԭ�е��ڴ���Դ
		data = new_data;
		capacity = new_capacity;
	}
}

// ׷���ַ�
void String::push_back(char ch)
{
	if (size == capacity)
	{
		// ���·����ڴ�
		// ���ж�capacity�Ƿ�Ϊ0�����Ϊ0���µ�����Ϊ2������Ϊԭ����2��
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		reserve(new_capacity);
	}
	data[size++] = ch;
	data[size] = '\0'; // ����ַ���������
}

// ׷���ַ���
void String::append(const char* str)
{
	size_t new_size = size + strlen(str);
	if (new_size > capacity)
	{
		// ���·����ڴ�
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		// ���ݵ��㹻�������ַ����Ĵ�С,��2��������
		while (new_capacity < new_size)
		{
			new_capacity *= 2;
		}
		reserve(new_capacity);
	}
	strcat(data, str);
	size = new_size;
}

// ����+=�����
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

// ���뺯��
String& String::insert(size_t pos, char ch)
{
	assert(pos <= size);
	if (size == capacity)
	{
		// ���·����ڴ�
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		reserve(new_capacity);
	}

	// ��posλ�ü��������ַ�����ƶ�һ��λ��
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
		// ���·����ڴ�
		size_t new_capacity = capacity == 0 ? 2 : 2 * capacity;
		// ���ݵ��㹻�������ַ����Ĵ�С,��2��������
		while (new_capacity < new_size)
		{
			new_capacity *= 2;
		}
		reserve(new_capacity);
	}

	// ��posλ�ü��������ַ�����ƶ�len��λ��
	for (size_t i = size + len; i > pos + len - 1; --i)
	{
		data[i] = data[i - len];
	}

	// ��str���뵽posλ��
	for (size_t i = 0; i < len; ++i)
	{
		data[pos + i] = str[i];
	}
	size = new_size;
	return *this;
}

// ɾ������
String& String::erase(size_t pos, size_t len)
{
	assert(pos < size);
	// ���len����pos���ַ���ĩβ�ĳ��ȣ�ֻɾ��pos���ַ���ĩβ�ĳ���
	if (len > size - pos) {
		data[pos] = '\0';
		size = pos;
	}
	else {
		// ��pos+lenλ�ü��������ַ���ǰ�ƶ�len��λ��
		size_t i = pos + len;
		while (i <= size)
		{
			data[pos++] = data[i++];
		}
		size -= len;
	}
	return *this;
}

// �����ַ�����С
void String::resize(size_t new_size, char ch)
{
	if (new_size > size)
	{
		if (new_size > capacity)
		{
			// ���·����ڴ�
			reserve(new_size);
		}

		// ��ch��ӵ��ַ���ĩβ
		for (size_t i = size; i < new_size; ++i)
		{
			data[i] = ch;
		}
	}
	data[new_size] = '\0'; // ����ַ���������
	size = new_size;
}


// ���Һ���
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

// ��������
String::~String()
{
	delete[] data;
}

// ���� C �ַ���
const char* String::c_str()const 
{
	return data;
}

// ������
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

// ��С���
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

// �����������
istream& operator>>(istream& is, String& str)
{
	char ch;
	ch = is.get();
	while (ch != ' ' && ch != '\n') {
		str.push_back(ch);
		ch = is.get();// ��ȡ��һ���ַ�,���Զ�ȡ�ո�
	}
	return is;
}
istream& getline(istream& is, String& str)
{
	char ch;
	ch = is.get();
	while (ch != '\n') {
		str.push_back(ch);
		ch = is.get();// ��ȡ��һ���ַ�,���Զ�ȡ�ո�
	}
	return is;
}
ostream& operator<<(ostream& os, const String& str)
{
	os << str.c_str();
	return os;
}

// ���رȽ������
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

// ����[]�����
char& String::operator[](size_t i)
{
	return data[i];
}

const char& String::operator[](size_t i) const
{
	return data[i];
}
