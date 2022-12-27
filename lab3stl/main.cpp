#include <iostream>
#include "Header.h"
#include <cmath>
#include <complex>
#include <typeinfo>
#include <vector>


template<typename T>
void GetValueFromUser(std::complex<T>& value)
{
    T real = 0;
    T imag = 0;
    std::cout << "Please enter the real part of complex number" << std::endl;
    std::cin>>real;
    std::cout << "Please enter the imaginary part of complex number" << std::endl;
    std::cin>>imag;
    value.real(real);
    value.imag(imag);
}

template <typename T>
bool IsValueInRange(const T& value, const T& left_border, const T& right_border)
{
    return (value >= left_border && value <= right_border);
}

template <typename T>
void GetValueFromUserInRange(T& value, const T& left_border, const T& right_border, const char* condition = "")
{
    std::cout << condition;
    while (true)
    {
        std::cin>>value;
        if (IsValueInRange(value, left_border, right_border))
        {
            return;
        }
        else
        {
            std::cout << "The value is not in range, try again" << std::endl;
        }
    }
}

template <typename Type_Vectors>
void MenuWorkingWithVector(Vector<Type_Vectors>& vector)
{
    bool working_with_vector = true;
    while (working_with_vector)
    {
        
        std::cout << vector << std::endl;
        std::cout << "You are now editing the first vector, Enter:" << std::endl;
        std::cout << "0 - Changing an element by index\n1 - Adding elements to a vector" << std::endl;
        std::cout << "2 - Dividing a vector by a number\n3 - Vector multiplication by a number " << std::endl;
        std::cout << "4 - Deleting an element by index\n5 - Finding the perpendicular" << std::endl;
        std::cout << "6 - Adding an element to the end of a vector\n7 - Inserting an element by index" << std::endl;
        std::cout << "8 - Output of an element by index\n9 - Finish working with the vector" << std::endl;
        int editing_vector = 0;
        GetValueFromUserInRange(editing_vector, (int)0, (int)9, "Enter the number in range[0;9] ");
        switch (editing_vector)
        {
            case (0):
            {
                if (vector.GetSize())
                {
                    try {
                        std::cout << "Enter a index of element to edit" << std::endl;
                        int index = 0;
                        std::cin>>index;
                    
                        std::cout << "Enter a new value for the element" << std::endl;
                        Type_Vectors value = 0;
                        std::cin>>value;
                        vector[index] = value;
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                break;
            }
            case (1):
            {
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
                //std::cout << "Enter a scalar" << std::endl;
                int count;
                Type_Vectors n;
                std::cout<<"Enter the vector length"<<std::endl;
                std::cin>>count;
                for (int i = 0; i<count; i++) {
                    std::cin>>n;
                    vector.PushBack(n);
                }
                /*bool flag = true;
                float n;
                while (flag == true) {
                    std::cin>>n;
                    if (n ==0) {
                        flag = false;
                    }
                    vector.PushBack(n);
                }*/
                break;
            }
            case (2):
            {
                std::cout << "Enter a scalar" << std::endl;
                int scalar = 0;
                std::cin>>scalar;
                try
                {
                    vector /= scalar;
                }
                catch (const char* ex)
                {
                    std::cout << ex << " Try again" << std::endl;
                    
                }
                break;
            }
            case (3):
            {
                std::cout << "Enter a scalar" << std::endl;
                int scalar = 0;
                std::cin>>scalar;
                vector *= scalar;
                std::cout<<vector<<std::endl;
                
                break;
                break;
            }
            case (4):
            {
                if (vector.GetSize())
                {
                    
                    std::cout << "Enter the index of element to delete" << std::endl;
                    int index = 0;
                    std::cin>>index;
                    try
                    {
                        vector.Erase(vector.Begin()+index);
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                else
                {
                    std::cout << "There are no elements to delete" << std::endl;
                }
                    
                break;
            }
            case (5):
            {
                
                Vector<Type_Vectors> vector2;
                Type_Vectors intermediate_result;
                Type_Vectors result_1;
                if (typeid(intermediate_result) != typeid(int)) {
                    for (int i = 0; i<vector.GetSize(); i++) {
                        vector2.PushBack(1);
                    }
                    
                    for (int i = 0; i<vector.GetSize(); i++) {
                        
                        //intermediate_result = -(vector.operator[](i) * vector2.operator[](i));
                        intermediate_result = -(vector[i] * vector2[i]);
                        result_1 = intermediate_result / vector[0];
                    }
                    
                    vector2.Insert(result_1, 0);
                    vector2.Erase(vector2.End()-1);
                    
                    Type_Vectors sqr;
                    for (int i = 0; i<vector2.GetSize(); i++) {
                        float inc;
                        //inc += vector2.operator[](i)*vector2.operator[](i);
                        inc += vector2[i]*vector2[i];
                        sqr = sqrt(inc);
                        
                    }
                    Vector<Type_Vectors> vector3;
                    for (int i = 0; i<vector2.GetSize(); i++) {
                        //vector3.PushBack(vector2.operator[](i)/sqr);
                        vector3.PushBack(vector2[i]/sqr);
                    }
                    std::cout<<"Perpendicular vector: ";
                    std::cout<<vector3<<std::endl;
                    std::cout<<"\n\n\n";
                }
                else{
                    std::cout<<"the perpendicular is not calculated"<<std::endl;
                }
                
                break;
            }
            case (6):
            {
                Type_Vectors number;
                std::cout<<"Enter the element: ";
                std::cin>>number;
                vector.PushBack(number);
                break;
            }
            case (7):
            {
                try {
                    std::cout<<"Enter the element: ";
                    Type_Vectors InsertNumber;
                    std::cin>>InsertNumber;
                    std::cout<<"Enter the index: ";
                    int InsertIndex;
                    std::cin>>InsertIndex;
                    vector.Insert(InsertNumber, InsertIndex);
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
                
                
            }
            case (8):
            {
                try {
                    std::cout<<"Enter the index: ";
                    int index;
                    std::cin>>index;
                    //std::cout<<vector.operator[](index)]<<std::endl;
                    std::cout<<vector[index]<<std::endl;
                    
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
            }
            case (9)://finish working
            {
                working_with_vector = false;
                break;
            }
                
        }
    }
}

template <typename Type_Vectors>
void MenuWorkingWithVector(Vector<std::complex<Type_Vectors>>& vector)
{
    bool working_with_vector = true;
    while (working_with_vector)
    {
        
        std::cout << vector << std::endl;
        std::cout << "You are now editing the first vector, Enter:" << std::endl;
        std::cout << "0 - Changing an element by index\n1 - Adding elements to a vector" << std::endl;
        std::cout << "2 - Dividing a vector by a number\n3 - Vector multiplication by a number " << std::endl;
        std::cout << "4 - Deleting an element by index\n5 - Finding the perpendicular" << std::endl;
        std::cout << "6 - Adding an element to the end of a vector\n7 - Inserting an element by index" << std::endl;
        std::cout << "8 - Output of an element by index\n9 - Finish working with the vector" << std::endl;
        int editing_vector = 0;
        GetValueFromUserInRange(editing_vector, (int)0, (int)9, "Enter the number in range[0;9] ");
        switch (editing_vector)
        {
            case (0):
            {
                if (vector.GetSize())
                {
                    try {
                        std::cout << "Enter a index of element to edit" << std::endl;
                        int index = 0;
                        std::cin>>index;
                    
                        std::cout << "Enter a new value for the element" << std::endl;
                        std::complex<Type_Vectors> value((Type_Vectors)0, (Type_Vectors)0);
                        GetValueFromUser(value);
                        vector[index] = value;
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                break;
            }
            case (1):
            {
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
                //std::cout << "Enter a scalar" << std::endl;
                int count;
                std::complex<Type_Vectors> n((Type_Vectors)0, (Type_Vectors)0);
                std::cout<<"Enter the vector length"<<std::endl;
                std::cin>>count;
                for (int i = 0; i<count; i++) {
                    std::cin>>n;
                    vector.PushBack(n);
                }
                /*bool flag = true;
                float n;
                while (flag == true) {
                    std::cin>>n;
                    if (n ==0) {
                        flag = false;
                    }
                    vector.PushBack(n);
                }*/
                break;
            }
            case (2):
            {
                std::cout << "Enter a scalar" << std::endl;
                std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
                GetValueFromUser(scalar);
                try
                {
                    vector /= scalar;
                }
                catch (const char* ex)
                {
                    std::cout << ex << " Try again" << std::endl;
                    
                }
                break;
            }
            case (3):
            {
                std::cout << "Enter a scalar" << std::endl;
                std::complex<Type_Vectors> scalar((Type_Vectors)0, (Type_Vectors)0);
                GetValueFromUser(scalar);
                vector *= scalar;
                std::cout<<vector<<std::endl;
                
                break;
                break;
            }
            case (4):
            {
                if (vector.GetSize())
                {
                    
                    std::cout << "Enter the index of element to delete" << std::endl;
                    int index = 0;
                    std::cin>>index;
                    try
                    {
                        vector.Erase(vector.Begin()+index);
                    }
                    catch (std::out_of_range& ex)
                    {
                        std::cout << ex.what() << " Try again" << std::endl;
                        
                    }
                }
                else
                {
                    std::cout << "There are no elements to delete" << std::endl;
                }
                    
                break;
            }
            case (5):
            {
                Vector<std::complex<Type_Vectors>> vector2;
                std::complex<Type_Vectors> intermediate_result((Type_Vectors)0, (Type_Vectors)0);
                std::complex<Type_Vectors> result_1((Type_Vectors)0, (Type_Vectors)0);
                
                for (int i = 0; i<vector.GetSize(); i++) {
                    vector2.PushBack(1);
                }
                
                for (int i = 0; i<vector.GetSize(); i++) {
                    
                    //intermediate_result = -(vector.operator[](i) * vector2.operator[](i));
                    intermediate_result = -(vector[i] * vector2[i]);
                    //result_1 = intermediate_result / vector.operator[](0);
                    result_1 = intermediate_result / vector[0];
                }
                
                vector2.Insert(result_1, 0);
                vector2.Erase(vector2.Begin()+vector2.GetSize()-1);
                std::complex<Type_Vectors> sqr((Type_Vectors)0, (Type_Vectors)0);
                
                for (int i = 0; i<vector2.GetSize(); i++) {
                    std::complex<Type_Vectors> inc((Type_Vectors)0, (Type_Vectors)0);
                    //inc += vector2.operator[](i)*vector2.operator[](i);
                    inc += vector2[i]*vector2[i];
                    sqr = sqrt(inc);
                    
                }
                Vector<std::complex<Type_Vectors>> vector3;
                for (int i = 0; i<vector2.GetSize(); i++) {
                    vector3.PushBack(vector2.operator[](i)/sqr);
                }
                std::cout<<"Perpendicular vector: ";
                std::cout<<vector3<<std::endl;
                std::cout<<"\n\n\n";
                break;
            }
            case (6):
            {
                std::complex<Type_Vectors> number((Type_Vectors)0, (Type_Vectors)0);
                std::cout<<"Enter the element: ";
                GetValueFromUser(number);
                vector.PushBack(number);
                break;
            }
            case (7):
            {
                try {
                    std::cout<<"Enter the element: ";
                    std::complex<Type_Vectors> InsertNumber((Type_Vectors)0, (Type_Vectors)0);
                    GetValueFromUser(InsertNumber);
                    std::cout<<"Enter the index: ";
                    int InsertIndex;
                    std::cin>>InsertIndex;
                    vector.Insert(InsertNumber, InsertIndex);
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
                
                
            }
            case (8):
            {
                try {
                    std::cout<<"Enter the index: ";
                    int index;
                    std::cin>>index;
                   
                    //std::cout<<vector.operator[](index)<<std::endl;
                    std::cout<<vector[index]<<std::endl;
                    
                } catch (std::out_of_range& ex) {
                    std::cout << ex.what() << " Try again" << std::endl;
                }
                break;
            }
            case (9)://finish working
            {
                working_with_vector = false;
                break;
            }
                
        }
    }
}

template <typename Type_Vectors>
void Menu(Type_Vectors)
{
    bool function_is_working = true;
    Vector<Type_Vectors> first_vector;
    Vector<Type_Vectors> second_vector;
    
    while (function_is_working)
    {
        std::cout << "First vector:" << first_vector << std::endl;
        std::cout << "\nSecond vector:" << second_vector << std::endl;
        std::cout << "Enter:\n0 - to work and edit with single vector" << std::endl;
        std::cout << "1 - to sum two vectors\n2 - to substract second vector from first" << std::endl;
        std::cout << "3 - to calculate the scalar product of two vectors\n4 - clear two vectors" << std::endl;
        std::cout << "5 - Print are two vectors equal or not\n6 - make first vector equal to second\n";
        std::cout << "7 - finish working with vectors" << std::endl;
        int action = 0;
        std::cin>>action;
        //GetValueFromUserInRange(action, (int)0, (int)7, "\nEnter a number in range [0;7]");
        switch (action)
        {
        case (0):
        {
            int order_number = 0;
            GetValueFromUserInRange(order_number, (int)1, (int)2, "Enter the order number of vector you wanted to edit");
            
            if (order_number == 1)
            {
                MenuWorkingWithVector(first_vector);
            }
            else
            {
                MenuWorkingWithVector(second_vector);
            }
            break;
        }
        case (1):
        {
            try
            {
                Vector<Type_Vectors> sum = first_vector + second_vector;
                std::cout << sum;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (2):
        {
            try
            {
                Vector<Type_Vectors> subtraction = first_vector - second_vector;
                std::cout << subtraction;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (3):
        {
            try
            {
                Type_Vectors scalar_product = first_vector * second_vector;
                std::cout << scalar_product << std::endl;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case (4):
        {
            first_vector.Clear();
            second_vector.Clear();
            break;
        }
        case (5):
        {
            first_vector == second_vector ? std::cout << "Vectors are equal" << std::endl :
                std::cout << "Vectors are different" << std::endl;
            
            break;
        }
        case (6):
        {
            first_vector = second_vector;
            break;
        }
        case (7):
        {
            function_is_working = false;
            break;
        }

        }
        
    }
}

template <typename Type_Vectors>
void Menu(std::complex<Type_Vectors>)
{
    bool function_is_working = true;
    Vector<std::complex<Type_Vectors>> first_vector;
    Vector<std::complex<Type_Vectors>> second_vector;
    while (function_is_working)
    {
        std::cout << "First vector:" << first_vector << std::endl;
        std::cout << "\nSecond vector:" << second_vector << std::endl;
        std::cout << "Enter:\n0 - to work and edit with single vector" << std::endl;
        std::cout << "1 - to sum two vectors\n2 - to substract second vector from first" << std::endl;
        std::cout << "3 - to calculate the scalar product of two vectors\n4 - clear two vectors" << std::endl;
        std::cout << "5 - Print are two vectors equal or not\n6 - make first vector equal to second\n";
        std::cout << "7 - finish working with vectors" << std::endl;
        int action = 0;
        GetValueFromUserInRange(action, (int)0, (int)7, "\nEnter a number in range [0;7]");
        switch (action)
        {
        case 0:
        {
            int order_number = 0;
            GetValueFromUserInRange(order_number, (int)1, (int)2, "Enter the order number of vector you wanted to edit");
            
            if (order_number == 1)
            {
                MenuWorkingWithVector(first_vector);
            }
            else
            {
                MenuWorkingWithVector(second_vector);
            }
            break;
        }
        case 1:
        {
            try
            {
                Vector<std::complex<Type_Vectors>> sum = first_vector + second_vector;
                std::cout << sum;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case 2:
        {
            try
            {
                Vector<std::complex<Type_Vectors>> subtraction = first_vector - second_vector;
                std::cout << subtraction;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case 3:
        {
            try
            {
                std::complex<Type_Vectors> scalar_product = first_vector * second_vector;
                std::cout << scalar_product << std::endl;
            }
            catch (const char* ex)
            {
                std::cout << ex << std::endl;
            }
            
            break;
        }
        case 4:
        {
            first_vector.Clear();
            second_vector.Clear();
            break;
        }
        case 5:
        {
            first_vector == second_vector ? std::cout << "Vectors are equal" << std::endl :
                std::cout << "Vectors are different" << std::endl;
            
            break;
        }
        case 6:
        {
            first_vector = second_vector;
            break;
        }
        case 7:
        {
            function_is_working = false;
            break;
        }

        }
        
    }
}




int main()
{
    bool working_with_vectors = true;
    while (working_with_vectors)
    {
        std::cout << "Enter:\n0 - to work with two Vector<int>" << std::endl;
        std::cout << "1 - to work with two Vector<float>" << std::endl;
        std::cout << "2 - to work with two Vector<double>" << std::endl;
        std::cout << "3 - to work with two Vector<std::complex<float>>" << std::endl;
        std::cout << "4 - to work with two Vector<std::complex<double>>" << std::endl;
        std::cout << "5 - to finish working with program" << std::endl;
        int option = 0;
        GetValueFromUserInRange(option, 0, 5);
        switch (option)
        {
            case 0:
            {
                Menu(0);
                std::cout << "int" << std::endl;
                break;
            }
            case 1:
            {
                Menu((float)0.0);
                std::cout << "float" << std::endl;
                break;
            }
            case 2:
            {
                Menu(0.0);
                std::cout << "double" << std::endl;
                break;
            }
            case 3:
            {
                Menu(std::complex<float>(0, 0));
                std::cout << "std::complex<float>" << std::endl;
                break;
            }
            case 4:
            {

                Menu(std::complex<double>(0, 0));
                std::cout << "std::complex<double>" << std::endl;
                break;
            }
            case 5:
            {
                working_with_vectors = false;
                break;
            }
        }
    }
}


