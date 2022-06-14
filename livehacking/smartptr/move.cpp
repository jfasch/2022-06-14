#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class String
{
public:
    String(char* p)
    : _p(p) {}

    String(String&& other)
    : _p(other._p)
    {
        other._p = nullptr;
    }

    String(const String&) = delete;
    String& operator=(const String&) = delete;

    String& operator=(String&& other)
    {
        delete[] _p;
        _p = other._p;
        other._p = nullptr;
        return *this;
    }

    ~String() { delete[] _p; }

    size_t size() const { return strlen(_p); }
    operator const char*() const { return _p; }

private:
    char* _p;
};

class HoldsAString
{
public:
    HoldsAString(String&& s)
    : _s(std::move(s)) {}

    const String& content() const { return _s; }

private:
    String _s;
};

class HoldsA___STD___String
{
public:
    HoldsA___STD___String(string&& s)
    : _s(std::move(s)) {}

    const string& content() const { return _s; }

private:
    string _s;
};


int main()
{
    {
        char *my_string = new char[]{"hallo"};
        String s(my_string);
        cout << "s: str: " << s << ", size: " << s.size() << endl;

        auto s1 = std::move(s);

        // ok, so I won't use s anymore, I KNOW!!!

        // strlist.push_back(s);

        cout << "s1: str: " << s1 << ", size: " << s1.size() << endl;
        // cout << "s: str: " << s << ", size: " << s.size() << endl;

        char* my_second_string = new char[]{"hello"};
        String s2(my_second_string);
        s2 = std::move(s1);
        cout << "s2: str: " << s2 << ", size: " << s2.size() << endl;

        HoldsAString has2(std::move(s2));
        cout << "has2.content(): " << has2.content() << endl;
    }

    {
        std::string s{"hallo"};
        HoldsA___STD___String has(move(s));

        cout << "has.content(): " << has.content() << endl;
        cout << "s: " << s << endl;
    }

    return 0;
}
