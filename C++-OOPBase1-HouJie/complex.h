#ifndef __COMPLEX__
#define __COMPLEX__

class complex
{
    public:
        complex (double r = 0, double i = 0)    // 构造函数没有返回值
            : re (r), im(i)                     // 列表式初始化，比函数体内赋值效率更高
        {}
        complex& operator += (const complex&);  // 成员函数
        double real () const { return re; }     // 要加const因为函数不会更改数据
        double imag () const { return im; }     // 要加const因为函数不会更改数据

    private:
        double re, im;

        friend complex& __doapl (complex*, const complex&); // 友元函数可以直接access private的数据, 第一个参数是指针而非引用是因为需要通过 指针->member 直接读取private的数据  
};

inline complex&
__doapl (complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r)
{
    return __doapl (this, r);
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex (real (x) + real (y),
                    imag (x) + imag (y));   // 少见的语法，用类加小括号创建一个临时对象
}

inline complex
operator + (const complex& x, double y)
{
    return complex (real (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex (x + real (y), imag (y));
}

#include <iostream>
ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real (x) << imag (x) << ')';
}

#endif