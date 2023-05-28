#include<iostream>
#include<utility>

template<typename T>
void swap(T& first, T&second)
{
    T tmp{std::move (first)};
    first = std::move(second);
    second = std::move(tmp);
}



class MyString {
    private:
        int m_capacity {0};
        char * m_buf {nullptr};
    public:
        MyString(int cap = 15);
        MyString (const MyString&);
        MyString& operator= (const MyString&);
        MyString& operator= (MyString&&) noexcept;
        MyString& operator+ (const MyString& str);
        MyString& operator+ (const std::string& st);
        MyString& operator+ (const char* th);
        MyString(MyString&&) noexcept;
        ~MyString();
        void SetCapacity(int cap);
        void SetBuf( char * ch);
        int GetCapacity()const;
        char* GetBuf()const;
        void MySwap(MyString&) noexcept;
        void PushBack(char*);
        size_t Size(char * );
        friend std::ostream& operator<< (std::ostream& ch, const MyString obj);
};
