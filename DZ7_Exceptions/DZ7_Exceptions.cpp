
#include <iostream>
#include "IntegerArray.h"

int main()
{
    setlocale(LC_ALL, "");
    try
    {
        IntegerArray testA(10);
        for (int i{ 0 }; i < 10; i++)
            testA[i] = i+1;
        testA.ShowArray();

        testA.resize(8);
        testA.insertBefore(20, 5);
        testA.remove(3);
        testA.insertAtEnd(30);
        testA.insertAtBegining(40);
        testA.insertAtBegining(1);
        
        
        testA.ShowArray();
        testA.find(1);
        testA.find(400);

        {
            IntegerArray testB(testA);
            testB = testA;
            testB = testB;
            testA = testA;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

