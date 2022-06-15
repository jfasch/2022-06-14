#include <iostream>

using namespace std;

class Sniff
{
public:
    Sniff()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Sniff(const Sniff&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    Sniff(Sniff&&)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

void f(const Sniff& s)
{
    cout << &s << endl;
}

void f(Sniff&& s)
{
    std::move(s);
    cout << &s << endl;
}

int main()
{
    Sniff s;
    f(std::move(s));
    return 0;
}
