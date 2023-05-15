#include <utility>
#include <iostream>

class TestMove
{
public:

    TestMove(double val)
    {
        m_value = val;
    }

    ~TestMove() = default;

    TestMove(const TestMove& rhs)
    {
        std::cout << "Copy constructor" << std::endl;

        if (this == &rhs)
            return;

        m_value = rhs.m_value;
    }

    TestMove(TestMove&& rhs) noexcept
    {
        std::cout << "Move constructor" << std::endl;

        if (this == &rhs)
            return;

        std::swap(m_value, rhs.m_value);
    }

    TestMove& operator=(TestMove&& rhs) noexcept
    {
        std::cout << "Move operator" << std::endl;

        if (this == &rhs)
            return *this;

        std::swap(m_value, rhs.m_value);

        return *this;
    }

    TestMove& operator=(const TestMove& rhs)
    {
        std::cout << "Copy operator" << std::endl;

        if (this == &rhs)
            return * this;

        m_value = rhs.m_value;
    }

    void PrintValue()
    {
        std::cout << m_value << std::endl;
    }

private:

    double m_value = 0;

};

class MoveTestWrapper
{
public:

    MoveTestWrapper(int x) :
        m_move(x)
    {
        std::cout << "Wrapper: Contructor!" << std::endl;

    }

    ~MoveTestWrapper()
    {
        std::cout << "Wrapper: Destructor!" << std::endl;
    }

    MoveTestWrapper(const MoveTestWrapper& rhs) noexcept :
        m_move(0)
    {
        std::cout << "Wrapper: Copy constructor" << std::endl;

        if (this == &rhs)
            return;

        m_move = rhs.m_move;
    }

    MoveTestWrapper(MoveTestWrapper&& rhs) noexcept :
        m_move(0)
    {
        std::cout << "Wrapper: Move constructor" << std::endl;

        if (this == &rhs)
            return;

        std::swap(m_move, rhs.m_move);
    }

    MoveTestWrapper& operator=(MoveTestWrapper&& rhs) noexcept
    {
        std::cout << "Wrapper: Move operator" << std::endl;

        if (this == &rhs)
            return *this;

        std::swap(m_move, rhs.m_move);

        return *this;
    }

    MoveTestWrapper& operator=(const MoveTestWrapper& rhs)
    {
        std::cout << "Wrapper: Copy operator" << std::endl;

        if (this == &rhs)
            return *this;

        m_move = rhs.m_move;
    }

private:

    TestMove m_move;
};


MoveTestWrapper testmove()
{
    MoveTestWrapper t(5);

    return t;
}