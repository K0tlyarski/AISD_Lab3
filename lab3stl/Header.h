
#ifndef Header_h
#define Header_h


#include <iostream>
#include <vector>
#include <complex>
#include <iterator>
template <class T>
class Vector
{
private:
    std::vector<T> v;
public:
    Vector(){
        std::vector<T> v;
    };
    Vector(const Vector<T>& rhs) = default;
    ~Vector() = default;
    Vector<T>& operator= (const Vector<T>& rhs) = default;
    size_t GetSize() const{
        return v.size();
    };
    void PushBack(const T& value);
    void Insert(const T& value, const size_t index);
    T& operator[] (const size_t index){
        if (index >= v.size()) throw std::out_of_range("Index is out of range");
        return v[index];
    };
    T operator[](const size_t index) const{
        if (index >= v.size()) throw std::out_of_range("Index is out of range");
        return v[index];
    };
    void Clear(){
        v.clear();
        
    };
    Vector<T>& operator+= (const Vector<T>& rhs);
    Vector operator+(const Vector<T>& rhs) const;
    Vector<T>& operator-= (const Vector<T>& rhs);
    Vector operator-(const Vector<T>& rhs) const;
    T  operator* (const Vector& rhs)
        {
            if (v.size() != rhs.GetSize()) throw("Different sizes");
            T result = 0;
            for (size_t i = 0; i < v.size(); i++)
            {
                result += rhs.v[i] * v[i];
            }
            return result;
        }
    Vector<T>& operator*=(const T& value);
    Vector operator*(const T& value) const;
    Vector<T>& operator/=(const T& value);
    Vector operator/(const T& value) const;
    bool operator==(const Vector<T>& rhs) const;
    bool operator!=(const Vector<T>& rhs) const;
//    auto Begin() const
//    {
//        return v.begin();
//    }
//    auto End() const
//    {
//        return v.end();
//    }
    auto begin() const
    {
        return v.begin();
    }

    auto end() const
    {
        return v.end();
    }
    
    auto Erase(typename std::vector<T>::const_iterator index)
    {
        v.erase(index);
        
    }
    
    std::complex<float> operator* (const Vector<std::complex<float>>& rhs) const
        {
            if (rhs.GetSize() != v.size()) throw "Bad dimensions";
            std::complex<float> scalar_product = 0;
            //for (size_t i = 0; i < v.size(); i++)
            for (auto i : v)
            {
                scalar_product += std::complex<float>(v[i].real() * rhs[i].real() - v[i].imag() * rhs[i].imag(), v[i].real() * rhs[i].imag() + v[i].imag() * rhs[i].real());
            }
            return scalar_product;
        }
    std::complex<double> operator* (const Vector<std::complex<double>>& rhs) const
        {
            if (rhs.GetSize() != v.size()) throw "Bad dimensions";
            std::complex<double> scalar_product = 0;
            //for (size_t i = 0; i < v.size(); i++)
            for (auto i : v)
            {
                scalar_product += std::complex<double>(v[i].real() * rhs[i].real() - v[i].imag() * rhs[i].imag(), v[i].real() * rhs[i].imag() + v[i].imag() * rhs[i].real());
            }
            return scalar_product;
        }

    

};



template<class T>
void Vector<T>::Insert(const T& value, const size_t index)
{
    if (index > v.size()) throw std::out_of_range("Index is out of range");
    v.insert(v.begin()+index, value);
}



template<class T>
void Vector<T>::PushBack(const T& value)
{
    v.push_back(value);
}

template<class T>
Vector<T>& Vector<T>::operator+= (const Vector<T>& rhs)
{
    if (v.size() != rhs.GetSize()) throw "Bad dimensions";
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] += rhs.v[i]; //??
    }
    return *this;
}
template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& rhs) const
{
    if (v.size() != rhs.GetSize()) throw "Bad dimensions";
    Vector result(*this);
    result += rhs;
    return result;
}
template<class T>
Vector<T>& Vector<T>::operator-= (const Vector<T>& rhs)
{
    if (v.size() != rhs.GetSize()) throw "Bad dimensions";
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] -= rhs.v[i]; //??
    }
    return *this;
}
template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& rhs) const
{
    if (v.size() != rhs.GetSize()) throw "Bad dimensions";
    Vector result(*this);
    result -= rhs;
    return result;
}

template<class T>
Vector<T>& Vector<T>::operator*=(const T& value)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] *= value;
    }
    return *this;
}

template<class T>
Vector<T> Vector<T>::operator*(const T& value) const
{
    Vector result(*this);
    result *= value;
    return result;
}

template<class T>
Vector<T>& Vector<T>::operator/=(const T& value)
{
    if (value == (T)0) throw "Dividing by zero is prohibited";
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] /= value;
    }
    return *this;
}
template<class T>
Vector<T> Vector<T>::operator/(const T& value) const
{
    Vector result(*this);
    result /= value;
    return result;
}
template<class T>
bool Vector<T>::operator==(const Vector<T>& rhs) const
{
    if (v.size() != rhs.GetSize()) return false;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (abs(v[i] - rhs[i]) > 0) return false;
    }
    return true;
}
template<>
bool Vector<double>::operator==(const Vector<double>& rhs) const
{
    double epsilon = 0.01;
    if (v.size() != rhs.GetSize()) return false;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (abs(v[i] - rhs[i]) > epsilon) return false;
    }
    return true;
}


template<class T>
bool Vector<T>::operator!=(const Vector<T>& rhs) const
{
    return !(*this == rhs);
}
template<class T>
Vector<T>& operator*=(const T& value, Vector<T>& rhs)
{
    rhs *= value;
    return rhs;
}
template<class T>
Vector<T> operator*(const T& value, const Vector<T>& rhs)
{
    Vector result(rhs);
    result *= value;
    return result;
}
template<class T>
 std::ostream& operator<< (std::ostream& out, const Vector<T>& vector)
{
    
    size_t size = vector.GetSize();
    if (!size)
    {
        out << "Vector is empty" << std::endl;
        return out;
    }
    out << "[";
    for (auto i : vector)
    {
        out << vector[i] << " , ";
    }
    out << vector[size - 1] << "] , the size of vector:" << size << std::endl;
    return out;

}
template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almost_equal(T x, T y, int ulp)
{
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::fabs(x-y) <= std::numeric_limits<T>::epsilon() * std::fabs(x+y) * ulp
        // unless the result is subnormal
        || std::fabs(x-y) < std::numeric_limits<T>::min();
}
//https://en.cppreference.com/w/cpp/types/numeric_limits/epsilon


#endif /* Header_h */
