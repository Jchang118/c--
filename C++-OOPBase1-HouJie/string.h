class String
{
public:
    String (const char* cstr = 0);  // 构造函数，c语言风格的字符串，只提供指针，默认到\0结束
    String (const String& str); // 拷贝构造
    String& operator= (const String& str); //拷贝赋值
    ~String(); //析构函数
    char* get_c_str() const {return m_data;}
private:
    char* m_data;
};

#include <cstring>
inline
String::String (const char* cstr = 0)
{
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else {
        m_data = new char[1];
        *m_data = '\0'; 
    }
}

inline
String::~String()
{
    delete[] m_data;
}

inline
String::String (const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline
String& String::operator= (const String& str)
{
    if (this == &str)
        return *this;
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this; // *取出this指针指向的object，传出去的一方不必要担心是否接收方接收value或reference
} 