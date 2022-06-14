#include <stdint.h>
#include <iostream>

enum class E : uint8_t
{
    ONE,
    TWO,
    THREE,
};

constexpr const char* msg(E e)
{
    switch (e) {
        case E::ONE:
            return "ONE";
        case E::TWO:
            return "TWO";
        case E::THREE:
            return "THREE";
    }
}

constexpr const char* s = "blah";
constexpr const std::string_view sv = s;


constexpr const char* ONE_STR = msg(E::ONE);

int main()
{
    E e_left = E::ONE;

    // write onto serial cable
    uint8_t i_cable = (uint8_t)e_left;

    // read from serial cable
    E e_right;
    switch ((E)i_cable) {
        case E::ONE:
            e_right = E::ONE;
            break;
        case E::TWO:
            e_right = E::TWO;
            break;
        case E::THREE:
            e_right = E::THREE;
            break;
    }
    
    if (e_right < E::ONE || e_right > E::THREE)
        // error
    {}

    std::cout << (uint8_t)e_right << std::endl;

    return 0;
}
