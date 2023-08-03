#include <iostream>
#include <random>


// TODO: Implement as template array class for n array size with m deletion.
class MontyHall
{
public:
    MontyHall() : m_doors{}, m_selection{ }
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist3(0, 3 - 1);
        m_doors[dist3(rng)] = Price::Car;
        m_selection = dist3(rng);
    }
    bool process()
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist3(0, 3 - 1);
        int deleteIndex;
        while (true)
        {
            deleteIndex = dist3(rng);
            if ((deleteIndex != m_selection) && (m_doors[deleteIndex] != ::MontyHall::Price::Car))
            {
                break;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (i == deleteIndex)
                continue;
            if (i == m_selection)
                continue;
            m_selection = i;
            break;
        }
        return m_doors[m_selection] == ::MontyHall::Price::Car;
    }
private:
    enum class Price : int { Goat, Car };

    Price m_doors[3];
    int m_selection;
};

int main()
{
    int totalCount{};
    int length = 1'000;
    for (int i = 0; i < length; i++)
    {
        MontyHall a;
        bool result = a.process();
        if (result)
            totalCount++;
    }
    std::cout << "MontyHall count number is: " << (100 * (double)totalCount / length) << "\n";
}