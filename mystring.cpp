#include"mystring.hpp"

MyString::MyString(int cap)
{
    m_capacity = cap;
    m_buf = new char [m_capacity];
    m_buf[0] = '\0';
}
MyString::~MyString()
{
    m_capacity = 0;
    delete[] m_buf;
    m_buf = nullptr;
}
void MyString::MySwap(MyString& tmp)noexcept
{
    swap(m_buf,tmp.m_buf);
    swap(m_capacity,tmp.m_capacity);
}

MyString::MyString(const MyString& ch )
{
    m_capacity = ch.m_capacity;
    m_buf = new char [m_capacity];
    strcpy(m_buf,ch.m_buf);
}
MyString& MyString::operator= (const MyString& tmp)
{
   if (this != &tmp)
   {
        MyString tmp1{tmp};
        MySwap(tmp1);
   }
   return *this;
}
MyString& MyString::operator=(MyString&& rvr)noexcept
{
    if(this != &rvr)
    {
        swap(*this,rvr);
    }
    return *this;
}
MyString& MyString::operator+(const MyString& other)
{
    PushBack(other.GetBuf());
    return *this;
}
MyString& MyString::operator+(const std::string& st)
{
    PushBack(const_cast<char*>(st.c_str()));
    return *this;
}
MyString& MyString::operator+(const char * other)
{
    PushBack(const_cast<char*>(other));
    return *this;
}

MyString::MyString(MyString&& tmp)noexcept
{
    swap(*this,tmp);
}
void MyString::SetCapacity(int tmp)
{
    m_capacity = tmp;
}
void MyString::SetBuf( char * ptr)
{
    m_buf = ptr;
}
int MyString::GetCapacity()const
{
    return m_capacity;
}
char * MyString::GetBuf() const
{
    return m_buf;
}
size_t MyString::Size(char * arr)
{
    return strlen(arr);
}

void MyString::PushBack( char * tmp)
{
    if ( m_capacity <(strlen(m_buf) + strlen(tmp)) + 1)
    {
        m_capacity += strlen(tmp) + 1;
        char * tmp1 = new char [m_capacity];
        strcpy(tmp1,m_buf);
        strcat(tmp1,tmp);
        delete[] m_buf;
        m_buf = tmp1;
        tmp1 = nullptr;
    }
    strcat(m_buf,tmp);
}

MyString operator+(const MyString& lhs, const MyString& rhs )
{   size_t tmpSize = lhs.GetCapacity() + rhs.GetCapacity();
    char * newBuf = new char[tmpSize];
    strcpy(newBuf,lhs.GetBuf());
    strcat(newBuf,rhs.GetBuf());
    MyString result(tmpSize);
    result.SetBuf(newBuf);

    return result;
    
}

std::ostream& operator<< (std::ostream& ch, const MyString obj)
{
    ch << obj.m_buf;
    return ch;
}
