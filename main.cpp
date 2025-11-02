// Write your solution here
// C++20 for C++
// /////////////////////////////////////////////////////////////////////////
// If C++: Your code is automatically compiled with a precompiled header. //
// 99% of includes / packages are already added for you.                  //
// You do NOT need to add your own includes here.                         //
// /////////////////////////////////////////////////////////////////////////

#include <cstddef>
#include <iostream>
#include <cstdint>

namespace getcracked 
{
    template <typename Element>
    class vector {
    public:
        vector() : _vectorMaxCapacity(1), _vectorCurrentSize(0)
        {
            _ptr = new Element[1];
        };

        virtual ~vector()
        {
            delete _ptr;
        };

        void push_back(Element element) 
        {
            if (_vectorMaxCapacity <= (_vectorCurrentSize + 1))
            {
                _vectorMaxCapacity = _vectorMaxCapacity * 3;
                Element *newPtr = new Element[_vectorMaxCapacity];
                newPtr = std::move(_ptr);
                _ptr = std::move(newPtr);
            }
            *(_ptr + _vectorCurrentSize) = element;
            ++_vectorCurrentSize;
        }

        const Element& at(std::size_t index) const
        {
            if (index >= _vectorCurrentSize)
                throw std::out_of_range("my_vector::at: index out of range");
            return *(_ptr+index);
        }

        std::size_t get_size() const 
        {
            return _vectorCurrentSize;
        }

        std::size_t get_capacity() const 
        {
            return _vectorMaxCapacity;
        }

        void shrink_to_fit() 
        {
            _vectorMaxCapacity = _vectorCurrentSize;
            Element *newPtr = new Element[_vectorMaxCapacity];
            newPtr = std::move(_ptr);
            _ptr = std::move(newPtr);
        }

        void pop_back() 
        {
            --_vectorCurrentSize;
        }

    private:
      // Data
      std::size_t _vectorMaxCapacity;
      std::size_t _vectorCurrentSize;
      Element *_ptr;
    };
}

int main(void)
{
    getcracked::vector<double> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "devrait afficher la size donc 3 : " << v.get_size() << std::endl;
    std::cout << "devrait afficher la capacity donc 9 : " << v.get_capacity() << std::endl;

    for (int i = 0; i < v.get_size(); ++i)
    {
        std::cout << "content = " << v.at(i) << std::endl;
    }

    return 0;
}
